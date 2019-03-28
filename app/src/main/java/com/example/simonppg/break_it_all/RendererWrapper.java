package com.example.simonppg.break_it_all;

import android.opengl.GLSurfaceView.Renderer;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * Created by Simonppg on 11/4/2017.
 */

class RendererWrapper implements Renderer {

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        GameLibJNIWrapper.surfaceCreated();
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        GameLibJNIWrapper.surfaceChanged(width, height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        GameLibJNIWrapper.drawFrame();
    }
}