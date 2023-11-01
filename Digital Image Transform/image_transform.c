#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"

void log_transform(unsigned char *input, float *output, int size, float c) {
    for (int i = 0; i < size; i++) {
        if (input[i] > 0) output[i] = c * log(1 + input[i]);
        else  output[i] = c * log(0.001);
    }
}


void power_transform(unsigned char *input, float *output, int size, float c, float gamma) {
    for (int i = 0; i < size; i++)  output[i] = c * pow(input[i], gamma);
}

void negation_transform(unsigned char *input, unsigned char *output, int size) {
    for (int i = 0; i < size; i++) output[i] = 255 - input[i];
}

void threshold_transform(unsigned char *input, unsigned char *output, int size, unsigned char t) {
    for (int i = 0; i < size; i++) output[i] = input[i] > t ? 255 : 0;
}

void print_matrix(float *matrix, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%.2f ", matrix[i * width + j]);
        }
        printf("\n");
    }
}

void write_image(const char *filename, unsigned char *image_data, int width, int height, int channels) {
    stbi_write_png(filename, width, height, channels, image_data, width * channels);
}

int main() {
    int width, height, channels;
    unsigned char *image_data = stbi_load("images.jpeg", &width, &height, &channels, 0);

    if (image_data == NULL) {
        printf("Failed to load the image.\n");
        return 1;
    }

    int size = width * height * channels;

    float *matrix = (float *)malloc(size * sizeof(float));
    unsigned char *output_image_data = (unsigned char *)malloc(size);

    for (int i = 0; i < size; i++) {
        matrix[i] = (float)image_data[i];
    }

    printf("Original Matrix:\n");
    print_matrix(matrix, width, height);

    log_transform(image_data, matrix, size, 1.0);

    printf("\nLog Transformed Matrix:\n");
    print_matrix(matrix, width, height);

    for (int i = 0; i < size; i++) {
        output_image_data[i] = (unsigned char)matrix[i];
    }

    write_image("log_transformed_image.png", output_image_data, width, height, channels);

    power_transform(image_data, matrix, size, 1.0, 2.0);

    printf("\nPower Transformed Matrix:\n");
    print_matrix(matrix, width, height);

    for (int i = 0; i < size; i++) {
        output_image_data[i] = (unsigned char)matrix[i];
    }

    write_image("power_transformed_image.png", output_image_data, width, height, channels);

    negation_transform(image_data, output_image_data, size);

    printf("\nNegation Transformed Matrix:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", output_image_data[i * width * channels + j * channels]);
        }
        printf("\n");
    }

    write_image("negation_transformed_image.png", output_image_data, width, height, channels);

    threshold_transform(image_data, output_image_data, size, 127);

    printf("\nThreshold Transformed Matrix:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", output_image_data[i * width * channels + j * channels]);
        }
        printf("\n");
    }

    write_image("threshold_transformed_image.png", output_image_data, width, height, channels);

    stbi_image_free(image_data);
    free(matrix);
    free(output_image_data);
    return 0;
}