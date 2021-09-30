#ifdef __cplusplus
extern "C" {
#endif

#ifndef DEPRECATED_ANDROID_FILES_MANAGER_HPP
#define DEPRECATED_ANDROID_FILES_MANAGER_HPP

#include <android/asset_manager.h>

extern AAssetManager *g_pAssetManager;

void load_asset_manager(AAssetManager *);
char* load_file(const char *filePath);

#endif // DEPRECATED_ANDROID_FILES_MANAGER_HPP

#ifdef __cplusplus
}
#endif
