#ifndef _LINUX_FILES_MANAGER_H_
#define _LINUX_FILES_MANAGER_H_

#include "../shared/FilesManager.hpp"

class LinuxFilesManager : public FilesManager {
public:
    char* loadFile(const char *filePath);
};

#endif //_LINUX_FILES_MANAGER_H_
