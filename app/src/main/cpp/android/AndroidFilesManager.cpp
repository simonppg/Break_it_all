// Copyright (c) 2021 Simon Puente
#include <android/asset_manager.h>
#include <malloc.h>

#include "AndroidFilesManager.hpp"

AndroidFilesManager::AndroidFilesManager(AAssetManager *assetManager) {
  this->assetManager = assetManager;
}

const string AndroidFilesManager::loadFile(const string filePath) {
  AAsset *file =
      AAssetManager_open(assetManager, filePath.c_str(), AASSET_MODE_BUFFER);

  size_t fileLength = static_cast<size_t>(AAsset_getLength(file));

  char *fileContent = static_cast<char *>(malloc(fileLength + 1));

  AAsset_read(file, fileContent, fileLength);

  // NOTE: For safety you can add a 0 terminating character at the end of your
  // file ...
  fileContent[fileLength] = '\0';

  AAsset_close(file);

  string str(fileContent);
  return str;
}
