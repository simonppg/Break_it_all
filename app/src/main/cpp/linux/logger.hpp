//
// Created by simonppg on 23/06/18.
//

#ifdef __cplusplus
extern "C" {
#endif

#ifndef BREAK_IT_ALL_LOGGER_H
#define BREAK_IT_ALL_LOGGER_H

#include <ctime>

// Terminal colors
#define KRED_COLOR  "\x1B[31m"
#define KGREEN_COLOR  "\x1B[32m"
#define KDEFAULT_COLOR  "\x1B[0m"

void logi(const char* fmt, ...);
void loge(const char* fmt, ...);

#define LOGI(fmt, ...) do { \
                            time_t now; \
                            time(&now); \
                            printf("%s ", ctime(&now)); \
                            printf("%sINFO: ", KGREEN_COLOR); \
                            printf(fmt, ##__VA_ARGS__); \
                            printf("%s\n", KDEFAULT_COLOR); \
                            } while (0)

#define LOGE(fmt, ...) do { \
                            time_t now; \
                            time(&now); \
                            printf("%s ", ctime(&now)); \
                            printf("%sERROR: ", KRED_COLOR); \
                            printf(fmt, ##__VA_ARGS__); \
                            printf("%s\n", KDEFAULT_COLOR); \
                            } while (0)


#endif //BREAK_IT_ALL_LOGGER_H

#ifdef __cplusplus
}
#endif