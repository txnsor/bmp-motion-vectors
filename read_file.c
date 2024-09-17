/**
 * @author Marc Browning
 * @name PNG Reader
 * @brief Opens an image file.
 */

#include <stdio.h>
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

    // validate that the file is a .png
    int png_signature[PNG_VALIDATION_SIZE] = {
        137, 80, 78, 71, 13, 10, 26, 10
    };
    char buffer[PNG_VALIDATION_SIZE];
    size_t elements_read = fread(buffer, sizeof(char), PNG_VALIDATION_SIZE, file);
    for (int i = 0; i < PNG_VALIDATION_SIZE; i++) {
        if (buffer[i] != png_signature[i]) {
            printf("Error: Byte %d read at position %d in file (expected %d). File is not in .png format.\n", buffer[i], i, png_signature[i]);
            return 0;
        }
    }
    // close the file
    fclose(file);
    return 0;
}