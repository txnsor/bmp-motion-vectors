/**
 * @author Marc Browning
 * @name BMP Reader
 * @brief Opens a .bmp image file.
 */

#include <stdio.h>
#include <string.h>
#define PNG_VALIDATION_SIZE 8

int main(int argc, char *argv[]) {
    if (argc <= 1) {return 0;}
    char * file_path = argv[1];

    // read the file
    FILE *file;
    file = fopen(file_path, "r");

    if (file == NULL) {
        printf("Error: File cannot be read.\n");
        return 0;
    }

    // validate that the file is a .bmp (WIP)
    char * bmp_signature;

    char buffer[PNG_VALIDATION_SIZE + 1];
    buffer[PNG_VALIDATION_SIZE] = '\0';

    size_t elements_read = fread(buffer, sizeof(char), PNG_VALIDATION_SIZE, file);

    for (int i = 0; i < PNG_VALIDATION_SIZE; i++) {
        printf("buffer: %d\nvalid:%d\n", buffer[i], bmp_signature[i]);
    }

    if (strcmp(buffer, bmp_signature) != 0) {
        printf("Error: Read %s (expected %s). File is not in .png format.\n", buffer, png_signature);
        return 0;
    }

    // close the file
    fclose(file);
    return 0;
}