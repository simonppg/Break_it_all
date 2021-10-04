// Copyright (c) 2021 Simon Puente
#include <cstdint>
#include <malloc.h>
#include <cstdio>
#include <cstring>

#include "LinuxFilesManager.hpp"
#include "logger.hpp"

LinuxFilesManager::LinuxFilesManager(const char *projectPath)
    : projectPath(projectPath) {}

char* LinuxFilesManager::loadFile(const char *filePath) {
  FILE *pFile;
#define PATH_SIZE 100
  char absolutePath[PATH_SIZE] = "\0";

  snprintf(absolutePath, PATH_SIZE, "%s%s%s", projectPath, "/../assets/", filePath);
#undef PATH_SIZE

  pFile = fopen(absolutePath, "r");

  if (pFile == NULL) {
    LOGE("Couldn't open the file: %s", absolutePath);
    return NULL;
  }

  fseek(pFile, 0, SEEK_END);
  int64_t fsize = ftell(pFile);
  fseek(pFile, 0, SEEK_SET); // same as rewind(f);

  char *pFileContent = (char *)malloc(sizeof(char) * fsize + 1);
  fread(pFileContent, fsize, 1, pFile);
  fclose(pFile);

  pFileContent[fsize] = 0;

  return pFileContent;
}
