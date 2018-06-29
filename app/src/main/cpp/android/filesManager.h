//
// Created by simonppg on 28/06/18.
//

#ifndef _FILES_MANAGER_H_
#define _FILES_MANAGER_H_

#include <android/asset_manager.h>

char* load_file(AAssetManager *assetManager, const char *filePath);

#endif //_FILES_MANAGER_H_
