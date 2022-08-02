// Copyright (c) 2022 Simon Puente
#ifndef COMMON_KEY_HPP
#define COMMON_KEY_HPP

enum class Key { UNKNOWN, A_KEY, S_KEY, D_KEY, W_KEY, L_KEY, ESCAPE_KEY };

enum class PressState { UNKNOWN, KEY_PRESSED, KEY_HOLDED, KEY_RELEASED };

#endif // COMMON_KEY_HPP
