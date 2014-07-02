package br.usp.benchdroid.app.benchmark;

/**
 * Created by Nivaldo
 * on 20/05/2014
 */
public abstract class Benchmark {

    static {
        System.loadLibrary("BenchDroid");
    }

    public long run(Algorithm type) {
//        long initialTime = System.currentTimeMillis();
        long initialTime = getClock();
        type.run(this);
//        long finalTime = System.currentTimeMillis();
        long finalTime = getClock();

        return finalTime - initialTime;
    }

    native long getClock();

    /***********************************************************************************/
    /*   Para cada entrada no enumerador Algorithm, deverá haver uma função abstrata   */
    /* equivalente aqui declarada e que seja chamada no método run(Benchmark) do enum  */
    /***********************************************************************************/
    protected abstract void superSwap();
    protected abstract void pi();
    protected abstract void multMatrix();
    protected abstract void fft();
}
