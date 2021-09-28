package com.example.game;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.MotionEvent;
import android.widget.Toast;

import com.example.game.jni.BreakItAll;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class BreakItAllActivity extends Activity {

    GLSurfaceView mView;

    @Override protected void onCreate(Bundle icicle) {
        super.onCreate(icicle);

        final int position = getPosition(getIntent());
        showPosition(position, getApplicationContext());

        mView = new GLSurfaceView(getApplication());
        mView.setEGLContextClientVersion(2);
        mView.setRenderer(getRenderer());
        mView.queueEvent(new Runnable() {
                @Override
                public void run() {
                    BreakItAll.init(position, getAssets());
                }
            });
        setContentView(mView);
    }

    private GLSurfaceView.Renderer getRenderer() {
        return new GLSurfaceView.Renderer() {
            @Override
            public void onSurfaceCreated(GL10 gl, EGLConfig config) {
                BreakItAll.surfaceCreated();
            }

            @Override
            public void onSurfaceChanged(GL10 gl, int width, int height) {
                BreakItAll.surfaceChanged(width, height);
            }

            @Override
            public void onDrawFrame(GL10 gl) {
                BreakItAll.drawFrame();
            }
        };
    }

    private void showPosition(int position, Context context) {
        Toast.makeText(context,
                    "Click ListItem Number " + position, Toast.LENGTH_SHORT)
                    .show();
    }

    private int getPosition(Intent intent) {
        Bundle extras;
        int defaultPosition = 0;

        if(intent == null) { return defaultPosition; }

        extras = intent.getExtras();

        if(extras == null) { return defaultPosition; }

        return extras.getInt("position");
    }

    @Override protected void onPause() {
        super.onPause();
        mView.onPause();
        mView.queueEvent(new Runnable() {
            @Override
            public void run() {
                BreakItAll.pause();
            }
        });
    }

    @Override protected void onResume() {
        super.onResume();
        mView.onResume();
        mView.queueEvent(new Runnable() {
            @Override
            public void run() {
                BreakItAll.resume();
            }
        });
    }

    @Override
    protected void onStop() {
        super.onStop();
        mView.queueEvent(new Runnable() {
            @Override
            public void run() {
                BreakItAll.stop();
            }
        });
    }

    @Override
    public boolean onTouchEvent(final MotionEvent e) {
        mView.queueEvent(new Runnable() {
            @Override
            public void run() {
                BreakItAll.on_touch_event(e.getX(), e.getY());
            }
        });
        return super.onTouchEvent(e);
    }
}
