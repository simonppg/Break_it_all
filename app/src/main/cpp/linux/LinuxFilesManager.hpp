#ifndef _FILES_MANAGER_H_
#define _FILES_MANAGER_H_

#include "../shared/FilesManager.hpp"

class LinuxFilesManager : public FilesManager {
public:
    char* loadFile(const char *filePath);
};

#endif //_FILES_MANAGER_H_
