//
// Created by simonppg on 28/06/18.
//

#include <malloc.h>

#include "filesManager.h"

char* load_file(AAssetManager *assetManager, const char *filePath) {
    AAsset* file = AAssetManager_open(assetManager, filePath, AASSET_MODE_BUFFER);

    size_t fileLength = (size_t) AAsset_getLength(file);

    char* fileContent = malloc(fileLength+1);

    AAsset_read(file, fileContent, fileLength);

    // For safety you can add a 0 terminating character at the end of your file ...
    fileContent[fileLength] = '\0';

    AAsset_close(file);

    return fileContent;
}
