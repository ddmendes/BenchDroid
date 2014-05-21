package br.usp.benchdroid.app;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

/**
 * Created by DaviDiório on 20/05/14.
 */
public class AlgorithmViewAdapter extends BaseAdapter {

    private String [][] algorithmDescriptionPairs;
    private LayoutInflater inflater;

    public AlgorithmViewAdapter(Context contexts, String [][] algorithmDescriptionPairs) {
        this.algorithmDescriptionPairs = algorithmDescriptionPairs;
        this.inflater = LayoutInflater.from(contexts);
    }

    public int getCount() {
        return this.algorithmDescriptionPairs.length;
    }

    @Override
    public Object getItem(int i) {
        return this.algorithmDescriptionPairs[i];
    }

    @Override
    public long getItemId(int i) {
        return i;
    }

    @Override
    public View getView(int i, View view, ViewGroup viewGroup) {

        if(view == null) {
            view = inflater.inflate(R.layout.algorithm_row, viewGroup, false);
        }

        String [] row = (String[]) getItem(i);
        TextView algName = (TextView) view.findViewById(R.id.algorithm_name);
        TextView algDesc = (TextView) view.findViewById(R.id.algorithm_description);

        algName.setText(row[0]);
        algDesc.setText(row[1]);

        return view;
    }

}