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
        Bundle extras = getIntent().getExtras();

        if (extras == null) {
            // TODO: handle error
        }

        final int position = extras.getInt("position");

        AssetManager mgr = getResources().getAssets();
        GameLibJNIWrapper.init(position, mgr);
        //GameLibJNIWrapper.load_asset_manager(mgr);

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