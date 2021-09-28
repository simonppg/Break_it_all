package com.example.game;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.MotionEvent;
import android.widget.Toast;

import com.example.game.jni.Game;

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
                    Game.surfaceCreated();
                }

                @Override
                public void onSurfaceChanged(GL10 gl, int width, int height) {
                    Game.surfaceChanged(width, height);
                }

                @Override
                public void onDrawFrame(GL10 gl) {
                    Game.drawFrame();
                }
            });
            mView.queueEvent(new Runnable() {
                @Override
                public void run() {
                    Game.init(position, getAssets());
                    Game.notifyCreate();
                }
            });
            setContentView(mView);
        }
    }

    @Override protected void onStart() {
        super.onStart();
        mView.queueEvent(new Runnable() {
            @Override
            public void run() {
                Game.notifyStart();
            }
        });
    }

    @Override protected void onPause() {
        super.onPause();
        mView.onPause();
        mView.queueEvent(new Runnable() {
            @Override
            public void run() {
                Game.pause();
                Game.notifyPause();
            }
        });
    }

    @Override protected void onResume() {
        super.onResume();
        mView.onResume();
        mView.queueEvent(new Runnable() {
            @Override
            public void run() {
                Game.resume();
                Game.notifyResume();
            }
        });
    }

    @Override protected void onRestart() {
        super.onRestart();
        mView.queueEvent(new Runnable() {
            @Override
            public void run() {
                Game.notifyRestart();
            }
        });
    }

    @Override
    protected void onStop() {
        super.onStop();
        mView.queueEvent(new Runnable() {
            @Override
            public void run() {
                Game.stop();
                Game.notifyStop();
            }
        });
    }

    @Override protected void onDestroy() {
        super.onDestroy();
        mView.queueEvent(new Runnable() {
            @Override
            public void run() {
                Game.notifyDestroy();
            }
        });
    }

    @Override
    public boolean onTouchEvent(final MotionEvent e) {
        mView.queueEvent(new Runnable() {
            @Override
            public void run() {
                Game.on_touch_event(e.getX(), e.getY());
            }
        });
        return super.onTouchEvent(e);
    }
}
