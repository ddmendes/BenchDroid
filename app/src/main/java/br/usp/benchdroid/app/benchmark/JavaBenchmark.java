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
        final int size = 20;
        int [][] m1 = new int[size][size];
        int [][] m2 = new int[size][size];
        int [][] mr = new int[size][size];

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                m1[i][j] = i * j;
                m2[i][j] = (int) Math.exp(i * j) / 3;
            }
        }

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                mr[i][j] = m1[i][j] * m2[j][i];
            }
        }
    }

    @Override
    protected void fft() {
        // TODO
    }
}
