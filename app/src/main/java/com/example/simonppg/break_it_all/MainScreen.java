package com.example.simonppg.break_it_all;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

/**
 * Created by simonppg on 21/03/18.
 */

public class MainScreen extends Activity {

    private static String LOGTAG = "MainScreen";
    private ListView items_list;

    @Override protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.i(LOGTAG, "Creating "+LOGTAG);
        setContentView(R.layout.main_screen);
        final String[] items =
                new String[]{"Window", "Item2"};

        ArrayAdapter<String> adaptador =
                new ArrayAdapter<String>(this,
                        android.R.layout.simple_list_item_1, items);

        items_list = (ListView)findViewById(R.id.my_list);

        items_list.setAdapter(adaptador);

        items_list.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view,
                                    int position, long id) {
                Toast.makeText(getApplicationContext(),
                        "Click ListItem Number " + position, Toast.LENGTH_LONG)
                        .show();
                Intent intent = new Intent(view.getContext(), WindowActivity.class);
                startActivity(intent);
            }
        });
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