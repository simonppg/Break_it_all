#include "triangle.hpp"

#include <GLES3/gl3.h>
#include <jni.h>
#include <android/asset_manager_jni.h>

extern "C" {
    JNIEXPORT void JNICALL
        Java_com_example_simonppg_break_1it_1all_WindowLibJNI_init(
                JNIEnv *env, jclass type, jobject assetManager) {
            (void)type;
            AAssetManager *nativeAssetManager = AAssetManager_fromJava(env, assetManager);
            init((void *)nativeAssetManager);
        }

    JNIEXPORT void JNICALL
        Java_com_example_simonppg_break_1it_1all_WindowLibJNI_surfaceCreated(JNIEnv *env, jclass type) {
            (void)env;
            (void)type;
            surfaceCreated();
        }

    JNIEXPORT void JNICALL
        Java_com_example_simonppg_break_1it_1all_WindowLibJNI_surfaceChanged(
                JNIEnv *env, jclass type, jint width, jint height) {
            (void)env;
            (void)type;
            surfaceChanged(width, height);
        }


    JNIEXPORT void JNICALL
        Java_com_example_simonppg_break_1it_1all_WindowLibJNI_drawFrame(
                JNIEnv *env, jclass type) {
            (void)env;
            (void)type;
            update();
            render();
        }

    JNIEXPORT void JNICALL
        Java_com_example_simonppg_break_1it_1all_WindowLibJNI_pause(
                JNIEnv *env, jclass type) {
            (void)env;
            (void)type;
            pause();
        }

    JNIEXPORT void JNICALL
        Java_com_example_simonppg_break_1it_1all_WindowLibJNI_resume(
                JNIEnv *env, jclass type) {
            (void)env;
            (void)type;
            resume();
        }
}