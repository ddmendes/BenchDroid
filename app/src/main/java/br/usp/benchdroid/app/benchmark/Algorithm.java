package br.usp.benchdroid.app.benchmark;

/**
 * Created by Nivaldo
 * on 17/06/2014
 */
public enum Algorithm {
    SUPER_SWAP {
        @Override public String getTitle() { return "SuperSwap"; }
        @Override public String getDescription() { return "Realiza 100 milhões de trocas"; }

        @Override public void run(Benchmark b) { b.superSwap(); }
    },

    PI {
        @Override public String getTitle() { return "Pi"; }
        @Override public String getDescription() { return "Calcula o número Pi, com 20 casas de precisão"; }

        @Override public void run(Benchmark b) { b.pi(); }
    },

    MULT_MATRIX {
        @Override public String getTitle() { return "MultMatrix"; }
        @Override public String getDescription() { return "Multiplicação de matrizes 250x250"; }

        @Override public void run(Benchmark b) { b.multMatrix(); }
    },

    FFT {
        @Override public String getTitle() { return "FFT"; }
        @Override public String getDescription() { return "Transformação Rápida de Fourrier, com 100.000 amostras"; }

        @Override public void run(Benchmark b) { b.fft(); }
    };

    public abstract String getTitle();
    public abstract String getDescription();

    public abstract void run(Benchmark b);
}
