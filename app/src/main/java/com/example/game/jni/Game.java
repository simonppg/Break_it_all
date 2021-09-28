package com.example.game.jni;

import android.content.res.AssetManager;

public class Game {
    static {
        System.loadLibrary("Game");
    }

    public static native void init(int position, AssetManager mgr);
    public static native void surfaceCreated();
    public static native void surfaceChanged(int width, int height);
    public static native void drawFrame();
    public static native boolean on_touch_event(double xpos, double ypos);
    public static native String[] getTestsList();

    // Activity lifecycle hooks notifiers
    public static native void notifyCreate();
    public static native void notifyStart();
    public static native void notifyResume();
    public static native void notifyRestart();
    public static native void notifyPause();
    public static native void notifyStop();
    public static native void notifyDestroy();
}
