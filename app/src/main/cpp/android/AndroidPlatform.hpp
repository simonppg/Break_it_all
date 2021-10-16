// Copyright (c) 2021 Simon Puente
#ifndef APP_SRC_MAIN_CPP_ANDROID_ANDROIDPLATFORM_HPP_
#define APP_SRC_MAIN_CPP_ANDROID_ANDROIDPLATFORM_HPP_

#include <android/asset_manager.h>

#include "AndroidFilesManager.hpp"
#include "AndroidLogger.hpp"

#include "../shared/FilesManager.hpp"
#include "../shared/Logger.hpp"
#include "../shared/Platform.hpp"

class AndroidPlatform : public Platform {
private:
  AndroidLogger *aLogger;
  AndroidFilesManager *aFilesManager;

public:
  explicit AndroidPlatform(AAssetManager *assetManager);
  ~AndroidPlatform();

  Logger *logger();
  FilesManager *filesManager();
};

#endif // APP_SRC_MAIN_CPP_ANDROID_ANDROIDPLATFORM_HPP_
