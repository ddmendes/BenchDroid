package br.usp.benchdroid.app;

import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import br.usp.benchdroid.app.benchmark.Algorithm;
import br.usp.benchdroid.app.benchmark.Benchmark;


public class MainActivity extends ActionBarActivity implements AdapterView.OnItemClickListener, View.OnClickListener {
    private Benchmark mBenchmark;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // TODO instantiate mBenchmark

        ListView algorithmsList = (ListView) findViewById(android.R.id.list);
        algorithmsList.setAdapter(new AlgorithmAdapter(this));
        algorithmsList.setOnItemClickListener(this);

        findViewById(R.id.algorithm_runAll).setOnClickListener(this);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        // TODO run a single test
        long result = mBenchmark.run(Algorithm.values()[position]);
    }

    @Override
    public void onClick(View v) {
        // TODO run all

        Algorithm[] algorithms = Algorithm.values();
        long result = 0;
        for (Algorithm a : algorithms) {
            result += mBenchmark.run(a);
        }
    }
}
