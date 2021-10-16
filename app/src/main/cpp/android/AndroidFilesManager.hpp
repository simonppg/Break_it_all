// Copyright (c) 2021 Simon Puente
#ifndef APP_SRC_MAIN_CPP_ANDROID_ANDROIDFILESMANAGER_HPP_
#define APP_SRC_MAIN_CPP_ANDROID_ANDROIDFILESMANAGER_HPP_

#include <android/asset_manager.h>

#include "../shared/FilesManager.hpp"

class AndroidFilesManager : public FilesManager {
private:
  AAssetManager *assetManager;

public:
  AndroidFilesManager(AAssetManager *);

  char *loadFile(const char *filePath);
};

#endif // APP_SRC_MAIN_CPP_ANDROID_ANDROIDFILESMANAGER_HPP_
