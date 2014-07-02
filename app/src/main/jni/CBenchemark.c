#include <sys/resource.h>
#include <android/log.h>
#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <jni.h>

#include "fft.h"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "hello-ndk", __VA_ARGS__))


jlong Java_br_usp_benchdroid_app_benchmark_Benchmark_getClock(JNIEnv* env, jobject self) {
    struct rusage self_usage;

    getrusage(RUSAGE_SELF, &self_usage);
    return (jlong) ( self_usage.ru_utime.tv_sec * 1000 + ( self_usage.ru_utime.tv_usec * 1.0f ) / 1000 );
}

jdouble Java_br_usp_benchdroid_app_benchmark_CBenchmark_superSwap(JNIEnv* env, jobject self) {
    const int limit = 100*1000*1000;
    int a = 10;
    int b = 0;
    int i, temp;
    for (i = 0; i < limit; i++) {
        temp = a;
        a = b;
        b = temp;
    }
}

double a(int n);
double b(int n);
double t(int n);
double p(int n);

double a(int n){
    if(n == 0){
        return 1;
    }else{
        return (a(n - 1) + b(n - 1))/2;
    }
}

double b(int n) {
    if(n == 0) {
        return 1/sqrt(2);
    } else {
        return sqrt(a(n - 1) * b(n - 1));
    }
}

double t(int n) {
    if(n == 0){
        return 0.25;
    } else {
        return t(n - 1) - p(n - 1) * pow(a(n - 1) - a(n), 2);
    }
}

double p(int n) {
    if(n == 0) {
        return 1;
    } else {
        return 2 * p(n - 1);
    }
}

double pi(int n) {
    return pow(a(n) + b(n), 2)/(4 * t(n));
}

void Java_br_usp_benchdroid_app_benchmark_CBenchmark_pi(JNIEnv* env, jobject self) {
    pi(20);
}

void Java_br_usp_benchdroid_app_benchmark_CBenchmark_multMatrix(JNIEnv* env, jobject self) {
    const int size = 500;
    srand(time(NULL));
    int m1[size][size];
    int m2[size][size];
    int mr[size][size];
    int i, j;

    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            m1[i][j] = rand() % size;
            m2[i][j] = rand() % size;
        }
    }

    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            mr[i][j] = m1[i][j] * m2[j][i];
        }
    }

}

void Java_br_usp_benchdroid_app_benchmark_CBenchmark_fft(JNIEnv* env, jobject self) {
    srand(time(NULL));
    int i;
    const int size = 10000;
    double real[size];
    double imag[size];

    for(i = 0; i < size; i++) {
        real[i] = rand() % size;
        imag[i] = rand() % size;
    }

    transform(real, imag, size);
}
