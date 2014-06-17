package br.usp.benchdroid.app;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;
import br.usp.benchdroid.app.benchmark.Algorithm;


/**
 * Created by DaviDiório on 20/05/14.
 */
public class AlgorithmAdapter extends BaseAdapter {
    private LayoutInflater mInflater;

    public AlgorithmAdapter(Context contexts) {
        this.mInflater = LayoutInflater.from(contexts);
    }

    public int getCount() {
        return Algorithm.values().length;
    }

    @Override
    public Object getItem(int i) {
        return Algorithm.values()[i];
    }

    @Override
    public long getItemId(int i) {
        return Algorithm.values()[i].ordinal();
    }

    @Override
    public View getView(int i, View view, ViewGroup viewGroup) {
        if(view == null) {
            view = mInflater.inflate(android.R.layout.simple_list_item_2, viewGroup, false);
        }

        Algorithm algorithm = (Algorithm) getItem(i);
        ((TextView) view.findViewById(android.R.id.text1)).setText(algorithm.getTitle());
        ((TextView) view.findViewById(android.R.id.text2)).setText(algorithm.getDescription());

        return view;
    }
}