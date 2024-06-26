//
// Created by Simonppg on 11/4/2017.
//

#include "game.hpp"
#include "filesManager.hpp"
#include "AndroidLogger.hpp"
#include "../shared/Logger.hpp"

Game *game;

Logger *logger = new AndroidLogger();

#ifdef __cplusplus
extern "C" {
#endif

#include <jni.h>
#include <android/asset_manager_jni.h>

JNIEXPORT void JNICALL Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_surfaceCreated
        (JNIEnv * env, jclass cls) {
    logger->sayHello();
    logger->logi("SurfaceCreated");
    logger->logi("%s","SurfaceCreated2");
    logger->logi("%s %d %s %f","aInt:", 15, "aFloat:", 123.123);
    std::string str = "This is a better test, print std::string str";
    logger->logi(str);
    int val = 101;
    logger->logi("%d", val);
    float pi = 3.1416f;
    logger->logi("%f", pi);
    const char *c_str = "a C string, const char*";
    logger->logi("%s", c_str);
    char aChar ='A';
    logger->logi(aChar);
     logger->logi("%s", c_str);
     logger->logi("%s %d", c_str, val);
     logger->logi("%s %d %f", c_str, val, pi);
     logger->logi("%s", "myNewStr");
     logger->logi("%s %d", "myNewStr", val);
     logger->logi("%s %d %f", "myNewStr", val, pi);
     logger->logi("%s %c", "myNewStr", 'F');
     logger->logi("%s %d %c", "myNewStr", val, 'F');
     logger->logi("%s %d %f %c", "myNewStr", val, pi, 'F');
     logger->logi("%c %s", 'R',c_str);
     logger->logi("%c %s %d", 'R',c_str, val);
     logger->logi("%c %s %d %f", 'R',c_str, val, pi);
    game->surfaceCreated();
}

JNIEXPORT void JNICALL Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_surfaceChanged
        (JNIEnv * env, jclass cls, jint width, jint height) {
    game->surfaceChanged(width, height);
}

JNIEXPORT void JNICALL Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_drawFrame
        (JNIEnv * env, jclass cls) {
    game->update();
    game->render();
}

JNIEXPORT bool JNICALL Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_on_1touch_1event
        (JNIEnv * env, jclass cls, jdouble xpos, jdouble ypos) {
    return game->on_touch_event(xpos, ypos);
}

JNIEXPORT jobjectArray JNICALL Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_getTestsList
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
Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_init(JNIEnv *env, jclass type,
                                                                jint position, jobject mgr) {
    AAssetManager *mgr2 = AAssetManager_fromJava(env, mgr);
    assert(mgr2 != nullptr);
    load_asset_manager(mgr2);

    assert(game == nullptr);
    game = Game::init(position, new AndroidLogger());
}

JNIEXPORT void JNICALL
Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_pause(JNIEnv *env, jclass type) {
    game->pause();
    delete game;
    game = nullptr;
}

JNIEXPORT void JNICALL
Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_resume(JNIEnv *env, jclass type) {
    game->resume();
}

JNIEXPORT void JNICALL
Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_stop(JNIEnv *env, jclass type) {
    delete game;
}

#ifdef __cplusplus
}
#endif
