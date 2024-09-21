#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdbool.h> 
#include "./read_file/read_file.h"

int main(int argc, char *argv[]) {
    // parse first argument on cmd line
    if (argc <= 1) {return 0;}
    char * filepath = argv[1];

    printf("file is bmp: %s\n", isBmp(filepath)?"true":"false");

    return 0;
}