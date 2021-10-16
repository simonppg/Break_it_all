#ifndef ANDROID_PLATFORM_HPP
#define ANDROID_PLATFORM_HPP

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
  AndroidPlatform(AAssetManager *assetManager);
  ~AndroidPlatform();

  Logger *logger();
  FilesManager *filesManager();
};

#endif // ANDROID_PLATFORM_HPP
