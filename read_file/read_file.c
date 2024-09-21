/**
 * @author Marc Browning
 * @name BMP Reader
 * @brief Opens a .bmp image file and gives functionality to return a matrix [(x, y, r, g, b)] on the heap.
 * 
 */

#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdbool.h> 
#include "./read_file.h"

/**
 * @brief The size of the .bmp file header.
 */
#define BMP_VALIDATION_SIZE 14
/**
 * @brief The "regular" signature of a .bmp (excluding OS/2 specific subformats)
 */
#define BMP_REGULAR "BM"

/**
 * @brief Validates that a filepath exists and is a .bmp file
 * @param filepath A file path string.
 */
bool isBmp(char * filepath) {
    FILE *file;
    file = fopen(filepath, "r");

    // check if file is NULL
    if (file == NULL) {
        printf("Error: File cannot be read.\n");
        fclose(file);
        return false;
    }

    // a buffer of characters 3 bytes long
    char buffer[3];
    // read first two bytes into buffer
    size_t elem_read = fread(buffer, sizeof(char), 2, file);

    // debug
    // printf("read: %s\n", buffer);
    // printf("bmp header: %s\n", BMP_REGULAR);

    // null terminator
    buffer[2] = '\0';
    // close the file
    fclose(file);

    // compare the two strings, and return
    return !(bool)strcmp(buffer, BMP_REGULAR);
}

// int main(int argc, char *argv[]) {
//     // parse first argument on cmd line
//     if (argc <= 1) {return 0;}
//     char * filepath = argv[1];

//     printf("file is bmp: %s\n", isBmp(filepath)?"true":"false");

//     return 0;
// }