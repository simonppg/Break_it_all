#include <GLES3/gl3.h>
#include <jni.h>
#include <android/asset_manager_jni.h>

void init(AAssetManager *assetManager) {}

void surfaceCreated() {}

void surfaceChanged(int w, int h) {
    glViewport(0, 0, w, h);
}

void update() {}

void render() {
    glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

void pause() {}

void resume() {}

extern "C" {
    JNIEXPORT void JNICALL
        Java_com_example_simonppg_break_1it_1all_WindowLibJNI_init(
                JNIEnv *env, jclass type, jobject assetManager) {
            (void)type;
            AAssetManager *nativeAssetManager = AAssetManager_fromJava(env, assetManager);
            init(nativeAssetManager);
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