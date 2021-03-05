package com.example.simonppg.break_it_all;

import android.content.res.AssetManager;

public class BreakItAllLibJNIWrapper {
    static {
        System.loadLibrary("BreakItAllLibJNIWrapper");
    }

    public static native void init(int position, AssetManager mgr);
    public static native void surfaceCreated();
    public static native void surfaceChanged(int width, int height);
    public static native void drawFrame();
    public static native boolean on_touch_event(double xpos, double ypos);
    public static native String[] getTestsList();
    public static native void pause();
    public static native void resume();
    public static native void stop();
}