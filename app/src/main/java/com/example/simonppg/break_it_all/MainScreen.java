package com.example.simonppg.break_it_all;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

/**
 * Created by simonppg on 21/03/18.
 */

public class MainScreen extends Activity {

    private static String LOGTAG = "MainScreen";

    @Override protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.i(LOGTAG, "Creating "+LOGTAG);
        setContentView(R.layout.main_screen);
    }

    @Override protected void onPause() {
        super.onPause();
    }

    @Override protected void onResume() {
        super.onResume();
    }

    public void onClick(View view) {
        Log.i(LOGTAG, "onClick");
        Intent intent = new Intent(this, GameActivity.class);
        startActivity(intent);
    }
}