// Copyright (c) 2021 Simon Puente
#include <malloc.h>
#include <cstdio>
#include <cstring>

#include "LinuxFilesManager.hpp"

char* LinuxFilesManager::loadFile(const char *filePath) {
    FILE *pFile;
    char absolutePath[80] = "\0";

#ifdef PROJECT_DIR
    strcat(absolutePath, PROJECT_DIR);
#endif
    //strcat(absolutePath, "/src/main/assets/");
    strcat(absolutePath, "/../assets/");
    strcat(absolutePath, filePath);

    pFile = fopen(absolutePath, "r");

    if(pFile == NULL) { return NULL; }

    fseek(pFile, 0, SEEK_END);
    long fsize = ftell(pFile);
    fseek(pFile, 0, SEEK_SET);  //same as rewind(f);

    char *pFileContent = (char *) malloc(sizeof(char) * fsize + 1);
    fread(pFileContent, fsize, 1, pFile);
    fclose(pFile);

    pFileContent[fsize] = 0;

    return pFileContent;
}
