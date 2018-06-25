//
// Created by simonppg on 23/06/18.
//

#ifndef BREAK_IT_ALL_LOGGER_H
#define BREAK_IT_ALL_LOGGER_H

void logi(const char* fmt, ...);
void loge(const char* fmt, ...);

#define LOGI(...) logi(__VA_ARGS__);
#define LOGE(...) loge(__VA_ARGS__);

#endif //BREAK_IT_ALL_LOGGER_H
