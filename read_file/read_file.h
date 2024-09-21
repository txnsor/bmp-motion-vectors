#include <stdbool.h> 
#include <stdint.h>
#ifndef READ_FILE_H
#define READ_FILE_H
    bool isBmp(char * filepath);

    int32_t bmpSize(char * filepath);

    int main(int argc, char *argv[]);
#endif
