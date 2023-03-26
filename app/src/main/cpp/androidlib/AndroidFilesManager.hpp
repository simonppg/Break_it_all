#ifndef APP_SRC_MAIN_CPP_ANDROIDLIB_ANDROIDFILESMANAGER_HPP_
#define APP_SRC_MAIN_CPP_ANDROIDLIB_ANDROIDFILESMANAGER_HPP_

#include <android/asset_manager.h>
#include <string>

#include "../platform/FilesManager.hpp"

class AndroidFilesManager final : public FilesManager {
private:
  AAssetManager *assetManager;

public:
  explicit AndroidFilesManager(AAssetManager *);

  const string loadFile(const string filePath);
};

#endif // APP_SRC_MAIN_CPP_ANDROIDLIB_ANDROIDFILESMANAGER_HPP_
