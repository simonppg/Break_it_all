#ifndef LINUX_FILES_MANAGER_HPP
#define LINUX_FILES_MANAGER_HPP

#include "../shared/FilesManager.hpp"

class LinuxFilesManager : public FilesManager {
public:
    char* loadFile(const char *filePath);
};

#endif // LINUX_FILES_MANAGER_HPP
