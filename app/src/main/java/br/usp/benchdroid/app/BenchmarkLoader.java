package br.usp.benchdroid.app;

import android.content.AsyncTaskLoader;
import br.usp.benchdroid.app.benchmark.Algorithm;

import java.util.List;


/**
 * Created by Nivaldo
 * on 17/06/2014
 */
public class BenchmarkLoader extends AsyncTaskLoader<Long> {

    private MainActivity          mActivity;
    private final List<Algorithm> mAlgorithmList;

    public BenchmarkLoader(MainActivity activity, List<Algorithm> algorithmList) {
        super(activity);
        mActivity = activity;
        mAlgorithmList = algorithmList;
    }

    @Override
    public Long loadInBackground() {
        long results = 0;
        for (Algorithm a : mAlgorithmList) {
            results += mActivity.getBenchmark().run(a);
        }
        return results;
    }

    @Override protected void onStartLoading() {
        forceLoad();
    }

    @Override
    protected void onStopLoading() {
        cancelLoad();
    }

    @Override
    protected void onReset() {
        super.onReset();
        onStopLoading();
    }
}
