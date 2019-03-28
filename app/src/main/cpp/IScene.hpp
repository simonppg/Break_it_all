//
// Created by simonppg on 3/27/19.
//

#ifndef BREAK_IT_ALL_ISCENE_H
#define BREAK_IT_ALL_ISCENE_H

#include "utils.hpp"

#ifdef __ANDROID_NDK__
#include "android/logger.hpp"
#include "android/filesManager.hpp"
#else
#include "linux/logger.hpp"
#include "linux/filesManager.hpp"
#endif

class IScene {
public:
    virtual void surfaceCreated() = 0;
    virtual void render() = 0;
    virtual void surfaceChanged(int width, int height) = 0;
};


#endif //BREAK_IT_ALL_ISCENE_H
