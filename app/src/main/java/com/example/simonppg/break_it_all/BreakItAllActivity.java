package com.example.simonppg.break_it_all;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.MotionEvent;
import android.widget.Toast;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class BreakItAllActivity extends Activity {

    GLSurfaceView mView;

    @Override protected void onCreate(Bundle icicle) {
        super.onCreate(icicle);

            mView = new GLSurfaceView(getApplication());
            mView.setEGLContextClientVersion(2);
            mView.setRenderer(new GLSurfaceView.Renderer() {
                @Override
                public void onSurfaceCreated(GL10 gl, EGLConfig config) {
                    BreakItAllLibJNIWrapper.surfaceCreated();
                }

                @Override
                public void onSurfaceChanged(GL10 gl, int width, int height) {
                    BreakItAllLibJNIWrapper.surfaceChanged(width, height);
                }

                @Override
                public void onDrawFrame(GL10 gl) {
                    BreakItAllLibJNIWrapper.drawFrame();
                }
            });
            mView.queueEvent(new Runnable() {
                @Override
                public void run() {
                    BreakItAllLibJNIWrapper.init(0, getAssets());
                }
            });
            setContentView(mView);
    }

    @Override protected void onPause() {
        super.onPause();
        mView.onPause();
        mView.queueEvent(new Runnable() {
            @Override
            public void run() {
                BreakItAllLibJNIWrapper.pause();
            }
        });
    }

    @Override protected void onResume() {
        super.onResume();
        mView.onResume();
        mView.queueEvent(new Runnable() {
            @Override
            public void run() {
                BreakItAllLibJNIWrapper.resume();
            }
        });
    }

    @Override
    protected void onStop() {
        super.onStop();
        mView.queueEvent(new Runnable() {
            @Override
            public void run() {
                BreakItAllLibJNIWrapper.stop();
            }
        });
    }

    @Override
    public boolean onTouchEvent(final MotionEvent e) {
        mView.queueEvent(new Runnable() {
            @Override
            public void run() {
                BreakItAllLibJNIWrapper.on_touch_event(e.getX(), e.getY());
            }
        });
        return super.onTouchEvent(e);
    }
}
