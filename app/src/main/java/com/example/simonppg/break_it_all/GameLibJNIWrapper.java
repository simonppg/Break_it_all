package com.example.simonppg.break_it_all;

import android.content.res.AssetManager;

/**
 * Created by Simonppg on 11/4/2017.
 */

public class GameLibJNIWrapper {
    static {
        System.loadLibrary("gameLibJNIWrapper");
    }

    public static native void on_surface_created();

    public static native void on_surface_changed(int width, int height);

    public static native void on_draw_frame();

    public static native boolean on_touch_event(double xpos, double ypos);

    public static native void load_asset_manager(AssetManager mgr);
}