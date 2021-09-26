#ifndef FILES_MANAGER_H
#define FILES_MANAGER_H

class FilesManager {
public:
    virtual char* loadFile(const char *filePath) = 0;
};

#endif // FILES_MANAGER_H
