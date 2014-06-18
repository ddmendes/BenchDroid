package br.usp.benchdroid.app.benchmark;

/**
 * Created by Nivaldo
 * on 17/06/2014
 */
public class JavaBenchmark extends Benchmark {

    @Override
    protected void superSwap() {
        final int limit = 1000*1000*1000; // One billion!
        int a = 10;
        int b = 0;
        for (int i = 0; i < limit; i++) {
            int temp = a;
            a = b;
            b = temp;
        }
    }

    @Override
    protected void pi() {
        // TODO
    }

    @Override
    protected void multMatrix() {
        // TODO
    }
}
