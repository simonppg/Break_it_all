#include <malloc.h>
#include <cstdio>
#include <cstring>

#include "LinuxFilesManager.hpp"
#include "logger.hpp"

LinuxFilesManager::LinuxFilesManager(const char *projectPath)
    : projectPath(projectPath) {}

char* LinuxFilesManager::loadFile(const char *filePath) {
  FILE *pFile;
  char absolutePath[80] = "\0";

  strcat(absolutePath, projectPath);
  strcat(absolutePath, "/../assets/");
  strcat(absolutePath, filePath);

  pFile = fopen(absolutePath, "r");

  if (pFile == NULL) {
    LOGE("Couldn't open the file: %s", absolutePath);
    return NULL;
  }

  fseek(pFile, 0, SEEK_END);
  long fsize = ftell(pFile);
  fseek(pFile, 0, SEEK_SET); // same as rewind(f);

  char *pFileContent = (char *)malloc(sizeof(char) * fsize + 1);
  fread(pFileContent, fsize, 1, pFile);
  fclose(pFile);

  pFileContent[fsize] = 0;

  return pFileContent;
}
