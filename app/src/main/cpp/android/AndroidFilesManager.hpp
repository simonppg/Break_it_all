#ifndef _ANDROID_FILES_MANAGER_H_
#define _ANDROID_FILES_MANAGER_H_

#include <android/asset_manager.h>

#include "../shared/FilesManager.hpp"

class AndroidFilesManager: public FilesManager {
private:
    AAssetManager *assetManager;

public:
    AndroidFilesManager(AAssetManager *);

    char* loadFile(const char *filePath);
};

#endif //_ANDROID_FILES_MANAGER_H_
