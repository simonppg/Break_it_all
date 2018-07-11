//
// Created by simonppg on 28/06/18.
//

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "filesManager.h"
#include "logger.h"

char* load_file(const char *filePath) {
    FILE *pFile;
    char absolutePath[80] = "\0";

#ifdef PROJECT_DIR
    strcat(absolutePath, PROJECT_DIR);
    strcat(absolutePath, "/src/main/assets/");
    strcat(absolutePath, filePath);
#endif

    pFile = fopen(absolutePath, "r");

    if(pFile == NULL)
    { 
        LOGE("\nCouldn't open the file: ");
        LOGE(absolutePath);
        return NULL;
    }

    fseek(pFile, 0, SEEK_END);
    long fsize = ftell(pFile);
    fseek(pFile, 0, SEEK_SET);  //same as rewind(f);

    char *pFileContent= malloc(fsize + 1);
    fread(pFileContent, fsize, 1, pFile);
    fclose(pFile);

    pFileContent[fsize] = 0;


    return pFileContent;
}
