#include "AndroidPlatform.hpp"

#include "AndroidLogger.hpp"
#include "AndroidFilesManager.hpp"

#include "../shared/Platform.hpp"
#include "../shared/Logger.hpp"
#include "../shared/FilesManager.hpp"

AndroidPlatform::AndroidPlatform(AAssetManager *assetManager) {
    aLogger = new AndroidLogger();
    aFilesManager = new AndroidFilesManager(assetManager);
}

AndroidPlatform::~AndroidPlatform () {
    delete aLogger;
    delete aFilesManager;
}

Logger* AndroidPlatform::logger() { return aLogger; }
FilesManager* AndroidPlatform::filesManager() { return aFilesManager; }

