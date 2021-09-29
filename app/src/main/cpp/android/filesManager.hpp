//
// Created by simonppg on 28/06/18.
//

#ifdef __cplusplus
extern "C" {
#endif

#ifndef FILES_MANAGER_HPP
#define FILES_MANAGER_HPP

#include <android/asset_manager.h>

extern AAssetManager *g_pAssetManager;

void load_asset_manager(AAssetManager *);
char* load_file(const char *filePath);

#endif // FILES_MANAGER_HPP

#ifdef __cplusplus
}
#endif
