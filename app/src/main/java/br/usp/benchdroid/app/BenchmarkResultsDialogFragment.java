package br.usp.benchdroid.app;

import android.app.AlertDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.app.LoaderManager;
import android.content.Loader;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.TextView;
import android.widget.ViewAnimator;
import br.usp.benchdroid.app.benchmark.Algorithm;

import java.util.ArrayList;
import java.util.List;
import java.util.Locale;


/**
 * Created by Nivaldo
 * on 17/06/2014
 */
public class BenchmarkResultsDialogFragment extends DialogFragment implements LoaderManager.LoaderCallbacks<Long> {

    private static final int VIEW_LOADING = 0;
    private static final int VIEW_CONTENT = 1;

    private static final String STATE_RESULT = "state.RESULT";

    private static final int LOAD_BENCHMARK = 0;

    private static final String ARGS_ALGORITHM = "args.ALGORITHM";
    private TextView mTextView;

    public static BenchmarkResultsDialogFragment instantiate(Algorithm algorithm) {
        Bundle args = new Bundle();
        args.putInt(ARGS_ALGORITHM, algorithm.ordinal());

        BenchmarkResultsDialogFragment fragment = new BenchmarkResultsDialogFragment();
        fragment.setArguments(args);

        return fragment;
    }

    public static BenchmarkResultsDialogFragment instantiate() {
        Bundle args = new Bundle();

        BenchmarkResultsDialogFragment fragment = new BenchmarkResultsDialogFragment();
        fragment.setArguments(args);

        return fragment;
    }


    private ViewAnimator mViewAnimator;

    @Override public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }
    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState) {
        View view = LayoutInflater.from(getActivity()).inflate(R.layout.fragment_benchmark_results, null);

        AlertDialog.Builder builder = new AlertDialog.Builder(getActivity());
        builder.setTitle("Resultados");
        builder.setView(view);
        builder.setPositiveButton(android.R.string.ok, null);

        mViewAnimator = (ViewAnimator) view.findViewById(android.R.id.toggle);
        mTextView = (TextView) view.findViewById(R.id.algorithm_results);

        getLoaderManager().initLoader(LOAD_BENCHMARK, null, this);

        return builder.create();
    }

    @Override public Loader<Long> onCreateLoader(int id, Bundle args) {
        mViewAnimator.setDisplayedChild(VIEW_LOADING);

        // Prepare the algorithm list
        int algorithmCode = getArguments().getInt(ARGS_ALGORITHM, -1);
        List<Algorithm> algorithmList = new ArrayList<Algorithm>();
        Algorithm[] algorithms = Algorithm.values();
        if (algorithmCode != -1) {
            algorithmList.add(algorithms[algorithmCode]);
        }
        else {
            for (Algorithm a : algorithms) {
                algorithmList.add(a);
            }
        }

        return new BenchmarkLoader((MainActivity) getActivity(), algorithmList);
    }
    @Override
    public void onLoadFinished(Loader<Long> loader, Long data) {
        mTextView.setText(String.format(Locale.getDefault(), "%.2f s", data/1000.));
        mViewAnimator.setDisplayedChild(VIEW_CONTENT);
    }
    @Override public void onLoaderReset(Loader<Long> loader) {}
}
