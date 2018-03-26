package com.example.simonppg.break_it_all;

import android.app.Activity;
import android.content.res.AssetManager;
import android.os.Bundle;
import android.util.Log;

public class GameActivity extends Activity {

    private static String LOGTAG = "GameActivity";
    protected MyGLSurfaceView graphicsView;

    @Override protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.i(LOGTAG, "Creating New Tutorial View");
        graphicsView = new MyGLSurfaceView(getApplication());
        AssetManager mgr = getResources().getAssets();
        GameLibJNIWrapper.load_asset_manager(mgr);
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