package br.usp.benchdroid.app.benchmark;

/**
 * Created by Nivaldo
 * on 17/06/2014
 */
public class CBenchmark extends Benchmark {
    @Override protected native void superSwap();
    @Override protected native void pi();
    @Override protected native void multMatrix();
    @Override protected native void fft();
}
