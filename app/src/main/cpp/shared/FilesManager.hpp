#ifndef _FILES_MANAGER_H_
#define _FILES_MANAGER_H_

class FilesManager {
public:
    virtual char* loadFile(const char *filePath) = 0;
};

#endif // _FILES_MANAGER_H_
