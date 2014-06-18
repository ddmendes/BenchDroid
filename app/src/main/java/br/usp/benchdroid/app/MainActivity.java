package br.usp.benchdroid.app;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.CompoundButton;
import android.widget.ListView;
import android.widget.Switch;
import br.usp.benchdroid.app.benchmark.Algorithm;
import br.usp.benchdroid.app.benchmark.Benchmark;
import br.usp.benchdroid.app.benchmark.CBenchmark;
import br.usp.benchdroid.app.benchmark.JavaBenchmark;


public class MainActivity extends Activity implements AdapterView.OnItemClickListener,
                                                      View.OnClickListener,
                                                      CompoundButton.OnCheckedChangeListener {

    private static final String STATE_BENCHMARK_TYPE = "state.BENCHMARK_TYPE";
    private static final short  BENCHMARK_C          = 1;
    private static final short  BENCHMARK_JAVA       = 2;

    private Benchmark mBenchmark;
    private short     mType;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // TODO instantiate mBenchmark
        mType = BENCHMARK_JAVA;
        if (savedInstanceState != null) {
            mType = savedInstanceState.getShort(STATE_BENCHMARK_TYPE);
        }
        switch (mType) {
            case BENCHMARK_C:
                mBenchmark = new CBenchmark();
                break;

            case BENCHMARK_JAVA:
                mBenchmark = new JavaBenchmark();
                break;
        }

        ListView algorithmsList = (ListView) findViewById(android.R.id.list);
        algorithmsList.setAdapter(new AlgorithmAdapter(this));
        algorithmsList.setOnItemClickListener(this);

        findViewById(R.id.algorithm_runAll).setOnClickListener(this);
    }

    @Override protected void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
        outState.putShort(STATE_BENCHMARK_TYPE, mType);
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);

        Switch isNative = (Switch) menu.findItem(R.id.action_switch).getActionView();
        isNative.setChecked(mType == BENCHMARK_C);
        isNative.setTextOn("C");
        isNative.setTextOff("Java");
        isNative.setOnCheckedChangeListener(this);

        return true;
    }
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_switch) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }

    @Override public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
        mType = isChecked ? BENCHMARK_C : BENCHMARK_JAVA;
        switch (mType) {
            case BENCHMARK_C:
                mBenchmark = new CBenchmark();
                break;

            case BENCHMARK_JAVA:
                mBenchmark = new JavaBenchmark();
                break;
        }
    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        Algorithm algorithm = Algorithm.values()[position];
        BenchmarkResultsDialogFragment.instantiate(algorithm).show(getFragmentManager(), null);
    }

    @Override
    public void onClick(View v) {
        BenchmarkResultsDialogFragment.instantiate().show(getFragmentManager(), null);
    }

    public Benchmark getBenchmark() {
        return mBenchmark;
    }
}
