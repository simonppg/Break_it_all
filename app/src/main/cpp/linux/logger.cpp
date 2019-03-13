//
// Created by simonppg on 23/06/18.
//

#ifdef __cplusplus
extern "C" {
#endif

#include <cstdio>

#include "logger.hpp"

void logi(const char* fmt, ...)
{
    printf("%s", fmt);
}

void loge(const char* fmt, ...)
{
    printf("%s", fmt);
}

#ifdef __cplusplus
}
#endif