// Copyright (c) 2021 Simon Puente
#include "LinuxFilesManager.hpp"

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

using std::string;

LinuxFilesManager::LinuxFilesManager(const char *projectPath)
    : projectPath(projectPath) {}

char *LinuxFilesManager::loadFile(const char *filePath) {
  FILE *pFile;
  string assetsDir("/../assets/");
  string absolutePath(projectPath + assetsDir + filePath);

  pFile = fopen(absolutePath.c_str(), "r");
  if (pFile == NULL) {
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
