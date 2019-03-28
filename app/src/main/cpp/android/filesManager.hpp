//
// Created by simonppg on 28/06/18.
//

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _FILES_MANAGER_H_
#define _FILES_MANAGER_H_

#include <android/asset_manager.h>

extern AAssetManager *g_pAssetManager;

void load_asset_manager(AAssetManager *);
char* load_file(const char *filePath);

#endif //_FILES_MANAGER_H_

#ifdef __cplusplus
}
#endif