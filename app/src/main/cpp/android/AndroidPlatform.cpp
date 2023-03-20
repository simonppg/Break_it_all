#include "AndroidPlatform.hpp"

#include "AndroidFilesManager.hpp"
#include "AndroidLogger.hpp"

#include "../platform/FilesManager.hpp"
#include "../platform/Logger.hpp"
#include "../platform/Platform.hpp"

AndroidPlatform::AndroidPlatform(AAssetManager *assetManager) {
  aLogger = new AndroidLogger();
  aFilesManager = new AndroidFilesManager(assetManager);
}

AndroidPlatform::~AndroidPlatform() {
  delete aLogger;
  delete aFilesManager;
}

Logger *AndroidPlatform::logger() { return aLogger; }
FilesManager *AndroidPlatform::filesManager() { return aFilesManager; }
