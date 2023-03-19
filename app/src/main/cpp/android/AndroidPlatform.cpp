#include "AndroidPlatform.hpp"

#include "AndroidFilesManager.hpp"
#include "AndroidLogger.hpp"

#include "../shared/platform/FilesManager.hpp"
#include "../shared/platform/Logger.hpp"
#include "../shared/platform/Platform.hpp"

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
