#ifndef ANDROID_PLATFORM_H
#define ANDROID_PLATFORM_H

#include <android/asset_manager.h>

#include "AndroidLogger.hpp"
#include "AndroidFilesManager.hpp"

#include "../shared/Platform.hpp"
#include "../shared/Logger.hpp"
#include "../shared/FilesManager.hpp"

class AndroidPlatform : public Platform {
private:
    AndroidLogger *aLogger;
    AndroidFilesManager *aFilesManager;

public:
    AndroidPlatform(AAssetManager *assetManager);
    ~AndroidPlatform();

    Logger* logger();
    FilesManager* filesManager();
};

#endif // ANDROID_PLATFORM_H
