package com.example.simonppg.break_it_all;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

public class GameActivity extends Activity {

    private static String LOGTAG = "GameActivity";
    protected MyGLSurfaceView graphicsView;

    @Override protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.i(LOGTAG, "Creating New Tutorial View");
        graphicsView = new MyGLSurfaceView(getApplication());
        setContentView(graphicsView);
    }

    @Override protected void onPause() {
        super.onPause();
        graphicsView.onPause();
    }

    @Override protected void onResume() {
        super.onResume();
        graphicsView.onResume();
    }
}