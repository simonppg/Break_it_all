// Copyright (c) 2021 Simon Puente
#include "LinuxFilesManager.hpp"

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "logger.hpp"

LinuxFilesManager::LinuxFilesManager(const char *projectPath)
  : projectPath(projectPath) {}

char* LinuxFilesManager::loadFile(const char *filePath) {
  FILE *pFile;
#define PATH_SIZE 100
  char absolutePath[PATH_SIZE] = "\0";
  const char *assetsDir = "/../assets/";

  snprintf(absolutePath, PATH_SIZE, "%s", projectPath);
  snprintf(absolutePath, PATH_SIZE, "%s", assetsDir);
  snprintf(absolutePath, PATH_SIZE, "%s", filePath);
#undef PATH_SIZE

  pFile = fopen(absolutePath, "r");

  if (pFile == NULL) {
    LOGE("Couldn't open the file: %s", absolutePath);
    return NULL;
  }

  fseek(pFile, 0, SEEK_END);
  int64_t fsize = ftell(pFile);
  // same as rewind(f);
  fseek(pFile, 0, SEEK_SET);

  auto dummy = malloc(sizeof(char) * fsize + 1);
  char *pFileContent = reinterpret_cast<char *>(dummy);
  fread(pFileContent, fsize, 1, pFile);
  fclose(pFile);

  pFileContent[fsize] = 0;

  return pFileContent;
}
