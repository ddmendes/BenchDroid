package br.usp.benchdroid.app.benchmark;

/**
 * Created by Nivaldo
 * on 17/06/2014
 */
public enum Algorithm {
    SUPER_SWAP {
        @Override public String getTitle() { return "SuperSwap"; }
        @Override public String getDescription() { return "Realiza 1 bilhão de trocas"; }

        @Override public void run(Benchmark b) { b.superSwap(); }
    },

    PI {
        @Override public String getTitle() { return "Pi"; }
        @Override public String getDescription() { return "Calcula o número Pi"; }

        @Override public void run(Benchmark b) { b.pi(); }
    },

    MULT_MATRIX {
        @Override public String getTitle() { return "MultMatrix"; }
        @Override public String getDescription() { return "Multiplicação de matrizes 20x20"; }

        @Override public void run(Benchmark b) { b.multMatrix(); }
    };

    public abstract String getTitle();
    public abstract String getDescription();

    public abstract void run(Benchmark b);
}
