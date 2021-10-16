#include <android/asset_manager.h>
#include <malloc.h>

#include "AndroidFilesManager.hpp"

AndroidFilesManager::AndroidFilesManager(AAssetManager *assetManager) {
  this->assetManager = assetManager;
}

char *AndroidFilesManager::loadFile(const char *filePath) {
  AAsset *file = AAssetManager_open(assetManager, filePath, AASSET_MODE_BUFFER);

  size_t fileLength = (size_t)AAsset_getLength(file);

  char *fileContent = (char *)malloc(fileLength + 1);

  AAsset_read(file, fileContent, fileLength);

  // NOTE: For safety you can add a 0 terminating character at the end of your
  // file ...
  fileContent[fileLength] = '\0';

  AAsset_close(file);

  return fileContent;
}
