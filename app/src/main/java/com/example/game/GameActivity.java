package com.example.game;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.MotionEvent;
import android.widget.Toast;

import com.example.game.jni.Game;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public final class GameActivity extends Activity {

  /**
   * GLSurfaceView.
   */
  private GLSurfaceView mView;

  @Override
  protected void onCreate(final Bundle icicle) {
    super.onCreate(icicle);
    Bundle extras = getIntent().getExtras();

    GLSurfaceView.Renderer renderer = new GLSurfaceView.Renderer() {
      @Override
      public void onSurfaceCreated(final GL10 gl, final EGLConfig config) {
        Game.surfaceCreated();
      }

      @Override
      public void onSurfaceChanged(final GL10 gl, final int width,
          final int height) {
        Game.surfaceChanged(width, height);
      }

      @Override
      public void onDrawFrame(final GL10 gl) {
        Game.drawFrame();
      }
    };

    if (extras != null) {
      final int position = extras.getInt("position");
      String string = "Click ListItem Number " + position;
      Toast.makeText(getApplicationContext(), string,
          Toast.LENGTH_SHORT).show();

      mView = new GLSurfaceView(getApplication());

      mView.setEGLContextClientVersion(2);
      mView.setRenderer(renderer);
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

  @Override
  protected void onStart() {
    super.onStart();
    mView.queueEvent(new Runnable() {
      @Override
      public void run() {
        Game.notifyStart();
      }
    });
  }

  @Override
  protected void onResume() {
    super.onResume();
    mView.onResume();
    mView.queueEvent(new Runnable() {
      @Override
      public void run() {
        Game.notifyResume();
      }
    });
  }

  @Override
  protected void onRestart() {
    super.onRestart();
    mView.queueEvent(new Runnable() {
      @Override
      public void run() {
        Game.notifyRestart();
      }
    });
  }

  @Override
  protected void onPause() {
    super.onPause();
    mView.onPause();
    mView.queueEvent(new Runnable() {
      @Override
      public void run() {
        Game.notifyPause();
      }
    });
  }

  @Override
  protected void onStop() {
    super.onStop();
    mView.queueEvent(new Runnable() {
      @Override
      public void run() {
        Game.notifyStop();
      }
    });
  }

  @Override
  protected void onDestroy() {
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
