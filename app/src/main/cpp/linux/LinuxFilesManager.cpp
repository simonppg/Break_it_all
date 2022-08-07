// Copyright (c) 2021 Simon Puente
#include "LinuxFilesManager.hpp"

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

using std::string;

LinuxFilesManager::LinuxFilesManager(const string projectPath)
    : projectPath(projectPath) {}

const string LinuxFilesManager::loadFile(const string filePath) {
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

  char *content = reinterpret_cast<char *>(malloc(sizeof(char) * fsize + 1));
  fread(content, fsize, 1, pFile);
  fclose(pFile);

  content[fsize] = 0;

  string str(content);
  free(content);
  return str;
}
