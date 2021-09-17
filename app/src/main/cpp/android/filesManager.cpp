//
// Created by simonppg on 28/06/18.
//

#include <cassert>

#ifdef __cplusplus
extern "C" {
#endif

#include <malloc.h>
#include <android/asset_manager.h>

#include "filesManager.hpp"

AAssetManager *g_pAssetManager = NULL;

void load_asset_manager(AAssetManager *pAssetManager)
{
    assert(pAssetManager != NULL);

    g_pAssetManager = pAssetManager;
}

char* load_file(const char *filePath)
{
    assert(g_pAssetManager != NULL);

    AAsset* file = AAssetManager_open(g_pAssetManager, filePath, AASSET_MODE_BUFFER);

    size_t fileLength = (size_t) AAsset_getLength(file);

    char* fileContent = (char *) malloc(fileLength+1);

    AAsset_read(file, fileContent, fileLength);

    // For safety you can add a 0 terminating character at the end of your file ...
    fileContent[fileLength] = '\0';

    AAsset_close(file);

    return fileContent;
}

#ifdef __cplusplus
}
#endif