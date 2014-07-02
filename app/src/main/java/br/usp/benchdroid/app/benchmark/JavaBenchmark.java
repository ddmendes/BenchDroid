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
        GaussLegendre.pi(15);
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

    private static class GaussLegendre {

        private static double a(int n){
            if(n == 0){
                return 1;
            }else{
                return (a(n - 1) + b(n - 1))/2.0;
            }
        }

        private static double b(int n){
            if(n == 0){
                return 1.0/Math.sqrt(2.0);
            }else{
                return Math.sqrt(a(n - 1) * b(n - 1));
            }
        }

        private static double t(int n){
            if(n == 0){
                return 1.0/4.0;
            }else{
                return t(n - 1) - p(n - 1) * Math.pow(a(n - 1) - a(n), 2);
            }
        }

        private static double p(int n){
            if(n == 0){
                return 1;
            }else{
                return 2 * p(n - 1);
            }
        }

        public static double pi(int n){
            return Math.pow(a(n) + b(n), 2)/ (4 * t(n));
        }

    }
}
