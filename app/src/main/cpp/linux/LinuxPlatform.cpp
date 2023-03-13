#include "LinuxPlatform.hpp"

#include "LinuxFilesManager.hpp"
#include "LinuxLogger.hpp"

// #include "../shared/platform/FilesManager.hpp"
// #include "../shared/platform/Logger.hpp"
// #include "../shared/platform/Platform.hpp"

LinuxPlatform::LinuxPlatform() : Platform() {
#ifdef PROJECT_DIR
  const char *projectPath = PROJECT_DIR;
#else
  const char *projectPath = "";
#endif

  aLogger = new LinuxLogger();
  aFilesManager = new LinuxFilesManager(projectPath);
}

LinuxPlatform::~LinuxPlatform() {
  delete aLogger;
  delete aFilesManager;
}

Logger *LinuxPlatform::logger() { return aLogger; }
FilesManager *LinuxPlatform::filesManager() { return aFilesManager; }
