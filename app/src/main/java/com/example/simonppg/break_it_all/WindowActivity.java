package com.example.simonppg.break_it_all;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.widget.Toast;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class WindowActivity extends Activity {

    GLSurfaceView mView;

    @Override protected void onCreate(Bundle icicle) {
        super.onCreate(icicle);
        Bundle extras = getIntent().getExtras();

        if (extras != null) {
            int position = extras.getInt("position");
            Toast.makeText(getApplicationContext(),
                    "Click ListItem Number " + position, Toast.LENGTH_LONG)
                    .show();

            mView = new GLSurfaceView(getApplication());
            mView.setEGLContextClientVersion(2);
            mView.setRenderer(new GLSurfaceView.Renderer() {
                @Override
                public void onSurfaceCreated(GL10 gl, EGLConfig config) {
                    WindowLibJNI.surfaceCreated();
                }

                @Override
                public void onSurfaceChanged(GL10 gl, int width, int height) {
                    WindowLibJNI.surfaceChanged(width, height);
                }

                @Override
                public void onDrawFrame(GL10 gl) {
                    WindowLibJNI.drawFrame();
                }
            });
            mView.queueEvent(new Runnable() {
                @Override
                public void run() {
                    WindowLibJNI.init(getAssets());
                }
            });
            setContentView(mView);
        }
    }

    @Override protected void onPause() {
        super.onPause();
        mView.onPause();
        mView.queueEvent(new Runnable() {
            @Override
            public void run() {
                WindowLibJNI.pause();
            }
        });
    }

    @Override protected void onResume() {
        super.onResume();
        mView.onResume();
        mView.queueEvent(new Runnable() {
            @Override
            public void run() {
                WindowLibJNI.resume();
            }
        });
    }
}
