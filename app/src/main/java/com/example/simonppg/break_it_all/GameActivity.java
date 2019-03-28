package com.example.simonppg.break_it_all;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.MotionEvent;
import android.widget.Toast;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class GameActivity extends Activity {

    GLSurfaceView mView;

    @Override protected void onCreate(Bundle icicle) {
        super.onCreate(icicle);
        Bundle extras = getIntent().getExtras();

        if (extras != null) {
            final int position = extras.getInt("position");
            Toast.makeText(getApplicationContext(),
                    "Click ListItem Number " + position, Toast.LENGTH_SHORT)
                    .show();

            mView = new GLSurfaceView(getApplication());
            mView.setEGLContextClientVersion(2);
            mView.setRenderer(new GLSurfaceView.Renderer() {
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
            });
            mView.queueEvent(new Runnable() {
                @Override
                public void run() {
                    GameLibJNIWrapper.init(position, getAssets());
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
                GameLibJNIWrapper.pause();
            }
        });
    }

    @Override protected void onResume() {
        super.onResume();
        mView.onResume();
        mView.queueEvent(new Runnable() {
            @Override
            public void run() {
                GameLibJNIWrapper.resume();
            }
        });
    }

    @Override
    protected void onStop() {
        super.onStop();
        mView.queueEvent(new Runnable() {
            @Override
            public void run() {
                GameLibJNIWrapper.stop();
            }
        });
    }

    @Override
    public boolean onTouchEvent(final MotionEvent e) {
        mView.queueEvent(new Runnable() {
            @Override
            public void run() {
                GameLibJNIWrapper.on_touch_event(e.getX(), e.getY());
            }
        });
        return super.onTouchEvent(e);
    }
}
