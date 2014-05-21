package br.usp.benchdroid.app;

/**
 * Created by Nivaldo
 * on 20/05/2014
 */
public class JNITest {

    static {
        System.loadLibrary("BenchDroid");
    }

    public native String test();
}
