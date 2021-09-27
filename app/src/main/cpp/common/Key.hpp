#ifndef KEY_H
#define KEY_H

enum class Key {
    UNKNOWN,
    A_KEY,
    S_KEY,
    D_KEY,
    W_KEY,
    L_KEY
};

enum class PressState {
    UNKNOWN,
    KEY_PRESSED,
    KEY_HOLDED,
    KEY_RELEASED
};

#endif // KEY_H
