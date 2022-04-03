// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_LINUX_WINDOWMANAGER_WINDOWCANNOTBECREATED_HPP_
#define APP_SRC_MAIN_CPP_LINUX_WINDOWMANAGER_WINDOWCANNOTBECREATED_HPP_

#include <exception>

using namespace std;

class WindowCanNotBeCreated : public exception {
  public:
    virtual const char* what() const noexcept {
       return "Window can NOT be created";
    }
};

#endif // APP_SRC_MAIN_CPP_LINUX_WINDOWMANAGER_WINDOWCANNOTBECREATED_HPP_
