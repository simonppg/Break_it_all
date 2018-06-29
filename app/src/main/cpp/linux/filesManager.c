//
// Created by simonppg on 28/06/18.
//

#include <malloc.h>
#include <stdio.h>

#include "filesManager.h"

char* load_file(const char *filePath) {
    FILE *pFile;

    pFile = fopen(filePath, "r");

    if(pFile == NULL)
        return NULL;

    fseek(pFile, 0, SEEK_END);
    long fsize = ftell(pFile);
    fseek(pFile, 0, SEEK_SET);  //same as rewind(f);

    char *pFileContent= malloc(fsize + 1);
    fread(pFileContent, fsize, 1, pFile);
    fclose(pFile);

    pFileContent[fsize] = 0;


    return pFileContent;
}
