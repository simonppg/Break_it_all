#ifndef ANDROID_FILES_MANAGER_HPP
#define ANDROID_FILES_MANAGER_HPP

#include <android/asset_manager.h>

#include "../shared/FilesManager.hpp"

class AndroidFilesManager: public FilesManager {
private:
    AAssetManager *assetManager;

public:
    AndroidFilesManager(AAssetManager *);

    char* loadFile(const char *filePath);
};

#endif //ANDROID_FILES_MANAGER_HPP
