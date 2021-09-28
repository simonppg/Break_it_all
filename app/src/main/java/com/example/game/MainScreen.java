package com.example.game;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import com.example.game.jni.BreakItAllLibJNIWrapper;

public class MainScreen extends Activity {
    private final String LOG_TAG = "MainScreen";

    @Override protected void onCreate(Bundle savedInstanceState) {
        ListView items_list;

        super.onCreate(savedInstanceState);
        setContentView(R.layout.main_screen);

        Log.i(LOG_TAG, "Creating " + LOG_TAG);

        ArrayAdapter<String> adapter =
                new ArrayAdapter<>(this,
                        android.R.layout.simple_list_item_1, BreakItAllLibJNIWrapper.getTestsList());

        items_list = (ListView)findViewById(R.id.my_list);

        items_list.setAdapter(adapter);

        items_list.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view,
                                    int position, long id) {

                // Intent intent = new Intent(view.getContext(), BreakItAllActivity.class);
                Intent intent = new Intent(view.getContext(), GameActivity.class);
                intent.putExtra("position", position);
                startActivity(intent);
            }
        });
    }
}
