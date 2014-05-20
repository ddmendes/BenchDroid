package br.usp.benchdroid.app;

import android.app.Application;


/**
 * Created by Nivaldo
 * on 20/05/2014
 */
public class BenchDroidApplication extends Application {

    static {
        System.loadLibrary("BenchDroid");
    }
}
