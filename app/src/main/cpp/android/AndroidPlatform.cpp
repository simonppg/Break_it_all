// Copyright (c) 2021 Simon Puente
#include "AndroidPlatform.hpp"

#include "AndroidFilesManager.hpp"
#include "AndroidLogger.hpp"

#include "../shared/FilesManager.hpp"
#include "../shared/Logger.hpp"
#include "../shared/Platform.hpp"

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
