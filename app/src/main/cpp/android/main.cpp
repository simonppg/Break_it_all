#include "../common/Game.hpp"
#include "filesManager.hpp"
#include "AndroidPlatform.hpp"
#include "../shared/Platform.hpp"
#include "../shared/Logger.hpp"
#include "../shared/FilesManager.hpp"
#include "../common/EventFactory.hpp"
#include "../common/ScreenTouched.hpp"

#ifdef __cplusplus
extern "C" {
#endif

#include <jni.h>
#include <android/asset_manager_jni.h>

Game *game;
Platform *platform;
Logger *logger;

JNIEXPORT void JNICALL Java_com_example_game_jni_Game_surfaceCreated
        (JNIEnv * env, jclass cls) {
    game->surfaceCreated();
}

JNIEXPORT void JNICALL Java_com_example_game_jni_Game_surfaceChanged
        (JNIEnv * env, jclass cls, jint width, jint height) {
    game->surfaceChanged(width, height);
}

JNIEXPORT void JNICALL Java_com_example_game_jni_Game_drawFrame
        (JNIEnv * env, jclass cls) {
    game->update();
    game->render();
}

JNIEXPORT bool JNICALL Java_com_example_game_jni_Game_on_1touch_1event
        (JNIEnv * env, jclass cls, jdouble xpos, jdouble ypos) {
    EventFactory eventFactory = EventFactory();
    ScreenTouched *event = new ScreenTouched(xpos, ypos);
    game->dispatchEvent(event);
    return true;
}

JNIEXPORT jobjectArray JNICALL Java_com_example_game_jni_Game_getTestsList
        (JNIEnv * env, jclass cls) {
#define LEN 5
    const char *tests[LEN]={"SandBox", "Window", "Triangle", "Circle", "orthographic"};
    jstring str;
    jobjectArray test = nullptr;
    jsize len = LEN;
    int i;

    test = (*env).NewObjectArray(len, (*env).FindClass("java/lang/String"), 0);

    for(i = 0; i < LEN; i++)
    {
        str = (*env).NewStringUTF(tests[i]);
        (*env).SetObjectArrayElement(test, i, str);
    }

    return test;
}

JNIEXPORT void JNICALL
Java_com_example_game_jni_Game_init(JNIEnv *env, jclass type,
                                                                jint position, jobject mgr) {
    AAssetManager *mgr2 = AAssetManager_fromJava(env, mgr);
    assert(mgr2 != nullptr);
    load_asset_manager(mgr2);

    platform = new AndroidPlatform(mgr2);
    FilesManager *filesManager = platform->filesManager();
    logger = platform->logger();

    assert(game == nullptr);
    game = new Game(position, platform);
}

JNIEXPORT void JNICALL
Java_com_example_game_jni_Game_pause(JNIEnv *env, jclass type) {
    game->pause();
    delete game;
    game = nullptr;
}

JNIEXPORT void JNICALL
Java_com_example_game_jni_Game_resume(JNIEnv *env, jclass type) {
    game->resume();
}

JNIEXPORT void JNICALL
Java_com_example_game_jni_Game_stop(JNIEnv *env, jclass type) {
    delete game;
}

// ===== Activity lifecycle Hooks =====
JNIEXPORT void JNICALL
Java_com_example_game_jni_Game_notifyCreate(JNIEnv *env, jclass type) {
    logger->logi("notifyCreate");
}

JNIEXPORT void JNICALL
Java_com_example_game_jni_Game_notifyStart(JNIEnv *env, jclass type) {
    logger->logi("notifyStart");
}

JNIEXPORT void JNICALL
Java_com_example_game_jni_Game_notifyResume(JNIEnv *env, jclass type) {
    logger->logi("notifyResume");
}

JNIEXPORT void JNICALL
Java_com_example_game_jni_Game_notifyRestart(JNIEnv *env, jclass type) {
    logger->logi("notifyRestart");
}

JNIEXPORT void JNICALL
Java_com_example_game_jni_Game_notifyPause(JNIEnv *env, jclass type) {
    logger->logi("notifyPause");
}

JNIEXPORT void JNICALL
Java_com_example_game_jni_Game_notifyStop(JNIEnv *env, jclass type) {
    logger->logi("notifyStop");
}

JNIEXPORT void JNICALL
Java_com_example_game_jni_Game_notifyDestroy(JNIEnv *env, jclass type) {
    logger->logi("notifyDestroy");
}
// ===== Activity lifecycle Hooks =====

#ifdef __cplusplus
}
#endif
