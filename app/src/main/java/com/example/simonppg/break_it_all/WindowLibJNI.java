package com.example.simonppg.break_it_all;

import android.content.res.AssetManager;

public class WindowLibJNI {
    static {
        System.loadLibrary("window");
    }

    public static native void init(AssetManager assetManager);
    public static native void surfaceCreated();
    public static native void surfaceChanged(int width, int height);
    public static native void drawFrame();
    public static native void pause();
    public static native void resume();
}
