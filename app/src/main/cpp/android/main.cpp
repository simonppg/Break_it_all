//
// Created by Simonppg on 11/4/2017.
//

#include "../game.hpp"
#include "filesManager.hpp"

#ifdef __cplusplus
extern "C" {
#endif

#include <jni.h>
#include <android/asset_manager_jni.h>

JNIEXPORT void JNICALL Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_on_1surface_1created
        (JNIEnv * env, jclass cls) {
    on_surface_created();
}

JNIEXPORT void JNICALL Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_on_1surface_1changed
        (JNIEnv * env, jclass cls, jint width, jint height) {
    on_surface_changed(width, height);
}

JNIEXPORT void JNICALL Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_on_1draw_1frame
        (JNIEnv * env, jclass cls) {
    on_draw_frame();
}

JNIEXPORT bool JNICALL Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_on_1touch_1event
        (JNIEnv * env, jclass cls, jdouble xpos, jdouble ypos) {
    return on_touch_event(xpos, ypos);
}

JNIEXPORT void JNICALL
Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_load_1asset_1manager
        (JNIEnv *env, jclass type, jobject mgr) {
    AAssetManager *mgr2 = AAssetManager_fromJava(env, mgr);
    load_asset_manager(mgr2);
}

JNIEXPORT jobjectArray JNICALL Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_getTestsList
        (JNIEnv * env, jclass cls) {

#define LEN 2
    const char *tests[LEN]={"Window", "Triangle"};

    jstring str;
    jobjectArray test = 0;
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

#ifdef __cplusplus
}
#endif