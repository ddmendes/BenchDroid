#include <sys/resource.h>
#include <android/log.h>
#include <sys/time.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <jni.h>

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "hello-ndk", __VA_ARGS__))


jlong Java_br_usp_benchdroid_app_benchmark_Benchmark_getClock(JNIEnv* env, jobject self) {
    struct rusage self_usage;

    getrusage(RUSAGE_SELF, &self_usage);
    return (jlong) ( self_usage.ru_utime.tv_sec * 1000 + ( self_usage.ru_utime.tv_usec * 1.0f ) / 1000 );
}

jdouble Java_br_usp_benchdroid_app_benchmark_CBenchmark_superSwap(JNIEnv* env, jobject self) {
    jdouble start = Java_br_usp_benchdroid_app_benchmark_Benchmark_getClock(env, self);
    const int limit = 1000*1000*1000; // One billion!
    int a = 10;
    int b = 0;
    int i, temp;
    for (i = 0; i < limit; i++) {
        temp = a;
        a = b;
        b = temp;
    }

    jdouble end = Java_br_usp_benchdroid_app_benchmark_Benchmark_getClock(env, self);

    printf("Time: %d", end - start);
}

double a(int n){
       if(n == 0){
            return 1;
       }else{
             return (a(n - 1) + b(n - 1))/2;
       }
}

double b(int n){
       if(n == 0){
            return 1/sqrt(2);
       }else{
             return sqrt(a(n - 1) * b(n - 1));
       }
}

double t(int n){
       if(n == 0){
            return 0.25;
       }else{
             return t(n - 1) - p(n - 1) * pow(a(n - 1) - a(n), 2);
       }
}

double p(int n){
       if(n == 0){
            return 1;
       }else{
             return 2 * p(n - 1);
       }
}

double pi(int n){
       return pow(a(n) + b(n), 2)/(4 * t(n));
}

void Java_br_usp_benchdroid_app_benchmark_CBenchmark_pi(JNIEnv* env, jobject self) {
    pi(15);
}

void Java_br_usp_benchdroid_app_benchmark_CBenchmark_multMatrix(JNIEnv* env, jobject self) {
    int m1[20][20];
    int m2[20][20];
    int mr[20][20];

    m1[ 0 ][ 0 ] =  33 ;    m1[ 0 ][ 1 ] =  30 ;    m1[ 0 ][ 2 ] =  50 ;    m1[ 0 ][ 3 ] =  31 ;    m1[ 0 ][ 4 ] =  20 ;    m1[ 0 ][ 5 ] =  29 ;    m1[ 0 ][ 6 ] =  27 ; m1[ 0 ][ 7 ] =  10 ;    m1[ 0 ][ 8 ] =  26 ;    m1[ 0 ][ 9 ] =  3 ;     m1[ 0 ][ 10 ] =  7 ;    m1[ 0 ][ 11 ] =  49 ;   m1[ 0 ][ 12 ] =  22 ;        m1[ 0 ][ 13 ] =  19 ;   m1[ 0 ][ 14 ] =  39 ;   m1[ 0 ][ 15 ] =  40 ;   m1[ 0 ][ 16 ] =  35 ;   m1[ 0 ][ 17 ] =  44 ;   m1[ 0 ][ 18 ] =  26 ;        m1[ 0 ][ 19 ] =  10 ;
    m1[ 1 ][ 0 ] =  11 ;    m1[ 1 ][ 1 ] =  31 ;    m1[ 1 ][ 2 ] =  5 ;     m1[ 1 ][ 3 ] =  0 ;     m1[ 1 ][ 4 ] =  20 ;    m1[ 1 ][ 5 ] =  4 ;     m1[ 1 ][ 6 ] =  13 ; m1[ 1 ][ 7 ] =  26 ;    m1[ 1 ][ 8 ] =  28 ;    m1[ 1 ][ 9 ] =  30 ;    m1[ 1 ][ 10 ] =  31 ;   m1[ 1 ][ 11 ] =  6 ;    m1[ 1 ][ 12 ] =  39 ;        m1[ 1 ][ 13 ] =  42 ;   m1[ 1 ][ 14 ] =  44 ;   m1[ 1 ][ 15 ] =  13 ;   m1[ 1 ][ 16 ] =  5 ;    m1[ 1 ][ 17 ] =  35 ;   m1[ 1 ][ 18 ] =  23 ;        m1[ 1 ][ 19 ] =  8 ;
    m1[ 2 ][ 0 ] =  14 ;    m1[ 2 ][ 1 ] =  29 ;    m1[ 2 ][ 2 ] =  48 ;    m1[ 2 ][ 3 ] =  39 ;    m1[ 2 ][ 4 ] =  1 ;     m1[ 2 ][ 5 ] =  40 ;    m1[ 2 ][ 6 ] =  11 ; m1[ 2 ][ 7 ] =  21 ;    m1[ 2 ][ 8 ] =  27 ;    m1[ 2 ][ 9 ] =  34 ;    m1[ 2 ][ 10 ] =  20 ;   m1[ 2 ][ 11 ] =  33 ;   m1[ 2 ][ 12 ] =  13 ;        m1[ 2 ][ 13 ] =  33 ;   m1[ 2 ][ 14 ] =  21 ;   m1[ 2 ][ 15 ] =  27 ;   m1[ 2 ][ 16 ] =  10 ;   m1[ 2 ][ 17 ] =  28 ;   m1[ 2 ][ 18 ] =  29 ;        m1[ 2 ][ 19 ] =  37 ;
    m1[ 3 ][ 0 ] =  4 ;     m1[ 3 ][ 1 ] =  21 ;    m1[ 3 ][ 2 ] =  44 ;    m1[ 3 ][ 3 ] =  28 ;    m1[ 3 ][ 4 ] =  36 ;    m1[ 3 ][ 5 ] =  5 ;     m1[ 3 ][ 6 ] =  31 ; m1[ 3 ][ 7 ] =  12 ;    m1[ 3 ][ 8 ] =  10 ;    m1[ 3 ][ 9 ] =  7 ;     m1[ 3 ][ 10 ] =  49 ;   m1[ 3 ][ 11 ] =  31 ;   m1[ 3 ][ 12 ] =  24 ;        m1[ 3 ][ 13 ] =  47 ;   m1[ 3 ][ 14 ] =  20 ;   m1[ 3 ][ 15 ] =  14 ;   m1[ 3 ][ 16 ] =  0 ;    m1[ 3 ][ 17 ] =  9 ;    m1[ 3 ][ 18 ] =  20 ;        m1[ 3 ][ 19 ] =  31 ;
    m1[ 4 ][ 0 ] =  45 ;    m1[ 4 ][ 1 ] =  20 ;    m1[ 4 ][ 2 ] =  12 ;    m1[ 4 ][ 3 ] =  13 ;    m1[ 4 ][ 4 ] =  3 ;     m1[ 4 ][ 5 ] =  49 ;    m1[ 4 ][ 6 ] =  31 ; m1[ 4 ][ 7 ] =  31 ;    m1[ 4 ][ 8 ] =  48 ;    m1[ 4 ][ 9 ] =  22 ;    m1[ 4 ][ 10 ] =  38 ;   m1[ 4 ][ 11 ] =  43 ;   m1[ 4 ][ 12 ] =  4 ; m1[ 4 ][ 13 ] =  7 ;    m1[ 4 ][ 14 ] =  11 ;   m1[ 4 ][ 15 ] =  21 ;   m1[ 4 ][ 16 ] =  26 ;   m1[ 4 ][ 17 ] =  7 ;    m1[ 4 ][ 18 ] =  17 ;m1[ 4 ][ 19 ] =  40 ;
    m1[ 5 ][ 0 ] =  15 ;    m1[ 5 ][ 1 ] =  19 ;    m1[ 5 ][ 2 ] =  24 ;    m1[ 5 ][ 3 ] =  39 ;    m1[ 5 ][ 4 ] =  23 ;    m1[ 5 ][ 5 ] =  13 ;    m1[ 5 ][ 6 ] =  38 ; m1[ 5 ][ 7 ] =  33 ;    m1[ 5 ][ 8 ] =  44 ;    m1[ 5 ][ 9 ] =  31 ;    m1[ 5 ][ 10 ] =  15 ;   m1[ 5 ][ 11 ] =  33 ;   m1[ 5 ][ 12 ] =  48 ;        m1[ 5 ][ 13 ] =  3 ;    m1[ 5 ][ 14 ] =  45 ;   m1[ 5 ][ 15 ] =  4 ;    m1[ 5 ][ 16 ] =  3 ;    m1[ 5 ][ 17 ] =  7 ;    m1[ 5 ][ 18 ] =  29 ;        m1[ 5 ][ 19 ] =  5 ;
    m1[ 6 ][ 0 ] =  25 ;    m1[ 6 ][ 1 ] =  49 ;    m1[ 6 ][ 2 ] =  46 ;    m1[ 6 ][ 3 ] =  30 ;    m1[ 6 ][ 4 ] =  15 ;    m1[ 6 ][ 5 ] =  27 ;    m1[ 6 ][ 6 ] =  11 ; m1[ 6 ][ 7 ] =  9 ;     m1[ 6 ][ 8 ] =  8 ;     m1[ 6 ][ 9 ] =  39 ;    m1[ 6 ][ 10 ] =  46 ;   m1[ 6 ][ 11 ] =  42 ;   m1[ 6 ][ 12 ] =  42 ;        m1[ 6 ][ 13 ] =  3 ;    m1[ 6 ][ 14 ] =  35 ;   m1[ 6 ][ 15 ] =  26 ;   m1[ 6 ][ 16 ] =  22 ;   m1[ 6 ][ 17 ] =  45 ;   m1[ 6 ][ 18 ] =  1 ; m1[ 6 ][ 19 ] =  46 ;
    m1[ 7 ][ 0 ] =  50 ;    m1[ 7 ][ 1 ] =  39 ;    m1[ 7 ][ 2 ] =  9 ;     m1[ 7 ][ 3 ] =  45 ;    m1[ 7 ][ 4 ] =  13 ;    m1[ 7 ][ 5 ] =  42 ;    m1[ 7 ][ 6 ] =  28 ; m1[ 7 ][ 7 ] =  1 ;     m1[ 7 ][ 8 ] =  18 ;    m1[ 7 ][ 9 ] =  38 ;    m1[ 7 ][ 10 ] =  25 ;   m1[ 7 ][ 11 ] =  27 ;   m1[ 7 ][ 12 ] =  11 ;        m1[ 7 ][ 13 ] =  29 ;   m1[ 7 ][ 14 ] =  11 ;   m1[ 7 ][ 15 ] =  38 ;   m1[ 7 ][ 16 ] =  45 ;   m1[ 7 ][ 17 ] =  1 ;    m1[ 7 ][ 18 ] =  3 ; m1[ 7 ][ 19 ] =  12 ;
    m1[ 8 ][ 0 ] =  38 ;    m1[ 8 ][ 1 ] =  26 ;    m1[ 8 ][ 2 ] =  9 ;     m1[ 8 ][ 3 ] =  27 ;    m1[ 8 ][ 4 ] =  6 ;     m1[ 8 ][ 5 ] =  39 ;    m1[ 8 ][ 6 ] =  27 ; m1[ 8 ][ 7 ] =  17 ;    m1[ 8 ][ 8 ] =  47 ;    m1[ 8 ][ 9 ] =  6 ;     m1[ 8 ][ 10 ] =  36 ;   m1[ 8 ][ 11 ] =  25 ;   m1[ 8 ][ 12 ] =  39 ;        m1[ 8 ][ 13 ] =  49 ;   m1[ 8 ][ 14 ] =  19 ;   m1[ 8 ][ 15 ] =  18 ;   m1[ 8 ][ 16 ] =  21 ;   m1[ 8 ][ 17 ] =  16 ;   m1[ 8 ][ 18 ] =  31 ;        m1[ 8 ][ 19 ] =  3 ;
    m1[ 9 ][ 0 ] =  43 ;    m1[ 9 ][ 1 ] =  12 ;    m1[ 9 ][ 2 ] =  10 ;    m1[ 9 ][ 3 ] =  5 ;     m1[ 9 ][ 4 ] =  28 ;    m1[ 9 ][ 5 ] =  29 ;    m1[ 9 ][ 6 ] =  16 ; m1[ 9 ][ 7 ] =  45 ;    m1[ 9 ][ 8 ] =  25 ;    m1[ 9 ][ 9 ] =  13 ;    m1[ 9 ][ 10 ] =  5 ;    m1[ 9 ][ 11 ] =  34 ;   m1[ 9 ][ 12 ] =  11 ;        m1[ 9 ][ 13 ] =  30 ;   m1[ 9 ][ 14 ] =  5 ;    m1[ 9 ][ 15 ] =  12 ;   m1[ 9 ][ 16 ] =  6 ;    m1[ 9 ][ 17 ] =  36 ;   m1[ 9 ][ 18 ] =  4 ; m1[ 9 ][ 19 ] =  30 ;
    m1[ 10 ][ 0 ] =  46 ;   m1[ 10 ][ 1 ] =  9 ;    m1[ 10 ][ 2 ] =  7 ;    m1[ 10 ][ 3 ] =  10 ;   m1[ 10 ][ 4 ] =  18 ;   m1[ 10 ][ 5 ] =  39 ;   m1[ 10 ][ 6 ] =  6 ; m1[ 10 ][ 7 ] =  35 ;   m1[ 10 ][ 8 ] =  26 ;   m1[ 10 ][ 9 ] =  22 ;   m1[ 10 ][ 10 ] =  43 ;  m1[ 10 ][ 11 ] =  42 ;  m1[ 10 ][ 12 ] =  39 ;       m1[ 10 ][ 13 ] =  13 ;  m1[ 10 ][ 14 ] =  3 ;   m1[ 10 ][ 15 ] =  29 ;  m1[ 10 ][ 16 ] =  28 ;  m1[ 10 ][ 17 ] =  15 ;  m1[ 10 ][ 18 ] =  2 ;        m1[ 10 ][ 19 ] =  10 ;
    m1[ 11 ][ 0 ] =  41 ;   m1[ 11 ][ 1 ] =  7 ;    m1[ 11 ][ 2 ] =  38 ;   m1[ 11 ][ 3 ] =  1 ;    m1[ 11 ][ 4 ] =  28 ;   m1[ 11 ][ 5 ] =  20 ;   m1[ 11 ][ 6 ] =  15 ;        m1[ 11 ][ 7 ] =  6 ;    m1[ 11 ][ 8 ] =  23 ;   m1[ 11 ][ 9 ] =  38 ;   m1[ 11 ][ 10 ] =  30 ;  m1[ 11 ][ 11 ] =  9 ;   m1[ 11 ][ 12 ] =  4 ;        m1[ 11 ][ 13 ] =  39 ;  m1[ 11 ][ 14 ] =  6 ;   m1[ 11 ][ 15 ] =  47 ;  m1[ 11 ][ 16 ] =  2 ;   m1[ 11 ][ 17 ] =  48 ;  m1[ 11 ][ 18 ] =  11 ;       m1[ 11 ][ 19 ] =  8 ;
    m1[ 12 ][ 0 ] =  36 ;   m1[ 12 ][ 1 ] =  31 ;   m1[ 12 ][ 2 ] =  18 ;   m1[ 12 ][ 3 ] =  3 ;    m1[ 12 ][ 4 ] =  23 ;   m1[ 12 ][ 5 ] =  49 ;   m1[ 12 ][ 6 ] =  25 ;        m1[ 12 ][ 7 ] =  23 ;   m1[ 12 ][ 8 ] =  7 ;    m1[ 12 ][ 9 ] =  10 ;   m1[ 12 ][ 10 ] =  6 ;   m1[ 12 ][ 11 ] =  40 ;  m1[ 12 ][ 12 ] =  19 ;       m1[ 12 ][ 13 ] =  11 ;  m1[ 12 ][ 14 ] =  41 ;  m1[ 12 ][ 15 ] =  2 ;   m1[ 12 ][ 16 ] =  36 ;  m1[ 12 ][ 17 ] =  31 ;  m1[ 12 ][ 18 ] =  35 ;       m1[ 12 ][ 19 ] =  8 ;
    m1[ 13 ][ 0 ] =  24 ;   m1[ 13 ][ 1 ] =  13 ;   m1[ 13 ][ 2 ] =  50 ;   m1[ 13 ][ 3 ] =  38 ;   m1[ 13 ][ 4 ] =  20 ;   m1[ 13 ][ 5 ] =  38 ;   m1[ 13 ][ 6 ] =  33 ;        m1[ 13 ][ 7 ] =  29 ;   m1[ 13 ][ 8 ] =  44 ;   m1[ 13 ][ 9 ] =  44 ;   m1[ 13 ][ 10 ] =  30 ;  m1[ 13 ][ 11 ] =  10 ;  m1[ 13 ][ 12 ] =  37 ;       m1[ 13 ][ 13 ] =  34 ;  m1[ 13 ][ 14 ] =  29 ;  m1[ 13 ][ 15 ] =  27 ;  m1[ 13 ][ 16 ] =  4 ;   m1[ 13 ][ 17 ] =  38 ;  m1[ 13 ][ 18 ] =  32 ;       m1[ 13 ][ 19 ] =  9 ;
    m1[ 14 ][ 0 ] =  23 ;   m1[ 14 ][ 1 ] =  24 ;   m1[ 14 ][ 2 ] =  47 ;   m1[ 14 ][ 3 ] =  29 ;   m1[ 14 ][ 4 ] =  32 ;   m1[ 14 ][ 5 ] =  32 ;   m1[ 14 ][ 6 ] =  36 ;        m1[ 14 ][ 7 ] =  50 ;   m1[ 14 ][ 8 ] =  50 ;   m1[ 14 ][ 9 ] =  13 ;   m1[ 14 ][ 10 ] =  15 ;  m1[ 14 ][ 11 ] =  48 ;  m1[ 14 ][ 12 ] =  47 ;       m1[ 14 ][ 13 ] =  18 ;  m1[ 14 ][ 14 ] =  21 ;  m1[ 14 ][ 15 ] =  40 ;  m1[ 14 ][ 16 ] =  49 ;  m1[ 14 ][ 17 ] =  25 ;  m1[ 14 ][ 18 ] =  49 ;       m1[ 14 ][ 19 ] =  30 ;
    m1[ 15 ][ 0 ] =  9 ;    m1[ 15 ][ 1 ] =  31 ;   m1[ 15 ][ 2 ] =  40 ;   m1[ 15 ][ 3 ] =  27 ;   m1[ 15 ][ 4 ] =  6 ;    m1[ 15 ][ 5 ] =  10 ;   m1[ 15 ][ 6 ] =  44 ;        m1[ 15 ][ 7 ] =  40 ;   m1[ 15 ][ 8 ] =  47 ;   m1[ 15 ][ 9 ] =  50 ;   m1[ 15 ][ 10 ] =  24 ;  m1[ 15 ][ 11 ] =  3 ;   m1[ 15 ][ 12 ] =  45 ;       m1[ 15 ][ 13 ] =  24 ;  m1[ 15 ][ 14 ] =  14 ;  m1[ 15 ][ 15 ] =  18 ;  m1[ 15 ][ 16 ] =  8 ;   m1[ 15 ][ 17 ] =  10 ;  m1[ 15 ][ 18 ] =  34 ;       m1[ 15 ][ 19 ] =  21 ;
    m1[ 16 ][ 0 ] =  6 ;    m1[ 16 ][ 1 ] =  5 ;    m1[ 16 ][ 2 ] =  45 ;   m1[ 16 ][ 3 ] =  10 ;   m1[ 16 ][ 4 ] =  7 ;    m1[ 16 ][ 5 ] =  27 ;   m1[ 16 ][ 6 ] =  25 ;        m1[ 16 ][ 7 ] =  13 ;   m1[ 16 ][ 8 ] =  42 ;   m1[ 16 ][ 9 ] =  17 ;   m1[ 16 ][ 10 ] =  37 ;  m1[ 16 ][ 11 ] =  15 ;  m1[ 16 ][ 12 ] =  4 ;        m1[ 16 ][ 13 ] =  44 ;  m1[ 16 ][ 14 ] =  49 ;  m1[ 16 ][ 15 ] =  49 ;  m1[ 16 ][ 16 ] =  48 ;  m1[ 16 ][ 17 ] =  49 ;  m1[ 16 ][ 18 ] =  33 ;       m1[ 16 ][ 19 ] =  12 ;
    m1[ 17 ][ 0 ] =  39 ;   m1[ 17 ][ 1 ] =  21 ;   m1[ 17 ][ 2 ] =  40 ;   m1[ 17 ][ 3 ] =  35 ;   m1[ 17 ][ 4 ] =  43 ;   m1[ 17 ][ 5 ] =  32 ;   m1[ 17 ][ 6 ] =  17 ;        m1[ 17 ][ 7 ] =  13 ;   m1[ 17 ][ 8 ] =  44 ;   m1[ 17 ][ 9 ] =  18 ;   m1[ 17 ][ 10 ] =  14 ;  m1[ 17 ][ 11 ] =  38 ;  m1[ 17 ][ 12 ] =  17 ;       m1[ 17 ][ 13 ] =  12 ;  m1[ 17 ][ 14 ] =  49 ;  m1[ 17 ][ 15 ] =  39 ;  m1[ 17 ][ 16 ] =  31 ;  m1[ 17 ][ 17 ] =  5 ;   m1[ 17 ][ 18 ] =  5 ;        m1[ 17 ][ 19 ] =  21 ;
    m1[ 18 ][ 0 ] =  26 ;   m1[ 18 ][ 1 ] =  34 ;   m1[ 18 ][ 2 ] =  50 ;   m1[ 18 ][ 3 ] =  6 ;    m1[ 18 ][ 4 ] =  11 ;   m1[ 18 ][ 5 ] =  2 ;    m1[ 18 ][ 6 ] =  16 ;        m1[ 18 ][ 7 ] =  29 ;   m1[ 18 ][ 8 ] =  43 ;   m1[ 18 ][ 9 ] =  1 ;    m1[ 18 ][ 10 ] =  11 ;  m1[ 18 ][ 11 ] =  31 ;  m1[ 18 ][ 12 ] =  17 ;       m1[ 18 ][ 13 ] =  8 ;   m1[ 18 ][ 14 ] =  37 ;  m1[ 18 ][ 15 ] =  47 ;  m1[ 18 ][ 16 ] =  33 ;  m1[ 18 ][ 17 ] =  23 ;  m1[ 18 ][ 18 ] =  30 ;       m1[ 18 ][ 19 ] =  29 ;
    m1[ 19 ][ 0 ] =  9 ;    m1[ 19 ][ 1 ] =  23 ;   m1[ 19 ][ 2 ] =  43 ;   m1[ 19 ][ 3 ] =  22 ;   m1[ 19 ][ 4 ] =  12 ;   m1[ 19 ][ 5 ] =  12 ;   m1[ 19 ][ 6 ] =  16 ;        m1[ 19 ][ 7 ] =  23 ;   m1[ 19 ][ 8 ] =  40 ;   m1[ 19 ][ 9 ] =  19 ;   m1[ 19 ][ 10 ] =  48 ;  m1[ 19 ][ 11 ] =  12 ;  m1[ 19 ][ 12 ] =  9 ;        m1[ 19 ][ 13 ] =  10 ;  m1[ 19 ][ 14 ] =  34 ;  m1[ 19 ][ 15 ] =  20 ;  m1[ 19 ][ 16 ] =  14 ;  m1[ 19 ][ 17 ] =  34 ;  m1[ 19 ][ 18 ] =  38 ;       m1[ 19 ][ 19 ] =  20 ;

    m2[ 0 ][ 0 ] =  16 ;    m2[ 0 ][ 1 ] =  32 ;    m2[ 0 ][ 2 ] =  19 ;    m2[ 0 ][ 3 ] =  21 ;    m2[ 0 ][ 4 ] =  24 ;    m2[ 0 ][ 5 ] =  17 ;    m2[ 0 ][ 6 ] =  18 ; m2[ 0 ][ 7 ] =  24 ;    m2[ 0 ][ 8 ] =  28 ;    m2[ 0 ][ 9 ] =  23 ;    m2[ 0 ][ 10 ] =  26 ;   m2[ 0 ][ 11 ] =  4 ;    m2[ 0 ][ 12 ] =  15 ;        m2[ 0 ][ 13 ] =  50 ;   m2[ 0 ][ 14 ] =  4 ;    m2[ 0 ][ 15 ] =  15 ;   m2[ 0 ][ 16 ] =  24 ;   m2[ 0 ][ 17 ] =  29 ;   m2[ 0 ][ 18 ] =  28 ;        m2[ 0 ][ 19 ] =  5 ;
    m2[ 1 ][ 0 ] =  13 ;    m2[ 1 ][ 1 ] =  17 ;    m2[ 1 ][ 2 ] =  29 ;    m2[ 1 ][ 3 ] =  3 ;     m2[ 1 ][ 4 ] =  10 ;    m2[ 1 ][ 5 ] =  48 ;    m2[ 1 ][ 6 ] =  3 ;  m2[ 1 ][ 7 ] =  3 ;     m2[ 1 ][ 8 ] =  20 ;    m2[ 1 ][ 9 ] =  37 ;    m2[ 1 ][ 10 ] =  36 ;   m2[ 1 ][ 11 ] =  7 ;    m2[ 1 ][ 12 ] =  39 ;        m2[ 1 ][ 13 ] =  0 ;    m2[ 1 ][ 14 ] =  25 ;   m2[ 1 ][ 15 ] =  13 ;   m2[ 1 ][ 16 ] =  13 ;   m2[ 1 ][ 17 ] =  10 ;   m2[ 1 ][ 18 ] =  39 ;        m2[ 1 ][ 19 ] =  4 ;
    m2[ 2 ][ 0 ] =  49 ;    m2[ 2 ][ 1 ] =  10 ;    m2[ 2 ][ 2 ] =  0 ;     m2[ 2 ][ 3 ] =  45 ;    m2[ 2 ][ 4 ] =  15 ;    m2[ 2 ][ 5 ] =  38 ;    m2[ 2 ][ 6 ] =  17 ; m2[ 2 ][ 7 ] =  25 ;    m2[ 2 ][ 8 ] =  16 ;    m2[ 2 ][ 9 ] =  5 ;     m2[ 2 ][ 10 ] =  0 ;    m2[ 2 ][ 11 ] =  45 ;   m2[ 2 ][ 12 ] =  23 ;        m2[ 2 ][ 13 ] =  25 ;   m2[ 2 ][ 14 ] =  6 ;    m2[ 2 ][ 15 ] =  35 ;   m2[ 2 ][ 16 ] =  0 ;    m2[ 2 ][ 17 ] =  32 ;   m2[ 2 ][ 18 ] =  16 ;        m2[ 2 ][ 19 ] =  47 ;
    m2[ 3 ][ 0 ] =  42 ;    m2[ 3 ][ 1 ] =  15 ;    m2[ 3 ][ 2 ] =  45 ;    m2[ 3 ][ 3 ] =  36 ;    m2[ 3 ][ 4 ] =  13 ;    m2[ 3 ][ 5 ] =  33 ;    m2[ 3 ][ 6 ] =  8 ;  m2[ 3 ][ 7 ] =  45 ;    m2[ 3 ][ 8 ] =  31 ;    m2[ 3 ][ 9 ] =  34 ;    m2[ 3 ][ 10 ] =  27 ;   m2[ 3 ][ 11 ] =  11 ;   m2[ 3 ][ 12 ] =  14 ;        m2[ 3 ][ 13 ] =  29 ;   m2[ 3 ][ 14 ] =  50 ;   m2[ 3 ][ 15 ] =  14 ;   m2[ 3 ][ 16 ] =  46 ;   m2[ 3 ][ 17 ] =  7 ;    m2[ 3 ][ 18 ] =  38 ;        m2[ 3 ][ 19 ] =  2 ;
    m2[ 4 ][ 0 ] =  44 ;    m2[ 4 ][ 1 ] =  22 ;    m2[ 4 ][ 2 ] =  39 ;    m2[ 4 ][ 3 ] =  42 ;    m2[ 4 ][ 4 ] =  19 ;    m2[ 4 ][ 5 ] =  44 ;    m2[ 4 ][ 6 ] =  48 ; m2[ 4 ][ 7 ] =  14 ;    m2[ 4 ][ 8 ] =  24 ;    m2[ 4 ][ 9 ] =  45 ;    m2[ 4 ][ 10 ] =  19 ;   m2[ 4 ][ 11 ] =  15 ;   m2[ 4 ][ 12 ] =  17 ;        m2[ 4 ][ 13 ] =  15 ;   m2[ 4 ][ 14 ] =  48 ;   m2[ 4 ][ 15 ] =  40 ;   m2[ 4 ][ 16 ] =  12 ;   m2[ 4 ][ 17 ] =  46 ;   m2[ 4 ][ 18 ] =  25 ;        m2[ 4 ][ 19 ] =  32 ;
    m2[ 5 ][ 0 ] =  37 ;    m2[ 5 ][ 1 ] =  6 ;     m2[ 5 ][ 2 ] =  47 ;    m2[ 5 ][ 3 ] =  24 ;    m2[ 5 ][ 4 ] =  12 ;    m2[ 5 ][ 5 ] =  4 ;     m2[ 5 ][ 6 ] =  24 ; m2[ 5 ][ 7 ] =  16 ;    m2[ 5 ][ 8 ] =  33 ;    m2[ 5 ][ 9 ] =  6 ;     m2[ 5 ][ 10 ] =  12 ;   m2[ 5 ][ 11 ] =  4 ;    m2[ 5 ][ 12 ] =  11 ;        m2[ 5 ][ 13 ] =  23 ;   m2[ 5 ][ 14 ] =  43 ;   m2[ 5 ][ 15 ] =  29 ;   m2[ 5 ][ 16 ] =  0 ;    m2[ 5 ][ 17 ] =  47 ;   m2[ 5 ][ 18 ] =  27 ;        m2[ 5 ][ 19 ] =  23 ;
    m2[ 6 ][ 0 ] =  7 ;     m2[ 6 ][ 1 ] =  5 ;     m2[ 6 ][ 2 ] =  49 ;    m2[ 6 ][ 3 ] =  25 ;    m2[ 6 ][ 4 ] =  34 ;    m2[ 6 ][ 5 ] =  3 ;     m2[ 6 ][ 6 ] =  43 ; m2[ 6 ][ 7 ] =  17 ;    m2[ 6 ][ 8 ] =  18 ;    m2[ 6 ][ 9 ] =  41 ;    m2[ 6 ][ 10 ] =  34 ;   m2[ 6 ][ 11 ] =  8 ;    m2[ 6 ][ 12 ] =  16 ;        m2[ 6 ][ 13 ] =  46 ;   m2[ 6 ][ 14 ] =  20 ;   m2[ 6 ][ 15 ] =  23 ;   m2[ 6 ][ 16 ] =  5 ;    m2[ 6 ][ 17 ] =  28 ;   m2[ 6 ][ 18 ] =  38 ;        m2[ 6 ][ 19 ] =  14 ;
    m2[ 7 ][ 0 ] =  49 ;    m2[ 7 ][ 1 ] =  15 ;    m2[ 7 ][ 2 ] =  8 ;     m2[ 7 ][ 3 ] =  20 ;    m2[ 7 ][ 4 ] =  49 ;    m2[ 7 ][ 5 ] =  1 ;     m2[ 7 ][ 6 ] =  14 ; m2[ 7 ][ 7 ] =  7 ;     m2[ 7 ][ 8 ] =  20 ;    m2[ 7 ][ 9 ] =  28 ;    m2[ 7 ][ 10 ] =  40 ;   m2[ 7 ][ 11 ] =  16 ;   m2[ 7 ][ 12 ] =  12 ;        m2[ 7 ][ 13 ] =  20 ;   m2[ 7 ][ 14 ] =  44 ;   m2[ 7 ][ 15 ] =  13 ;   m2[ 7 ][ 16 ] =  9 ;    m2[ 7 ][ 17 ] =  6 ;    m2[ 7 ][ 18 ] =  1 ; m2[ 7 ][ 19 ] =  36 ;
    m2[ 8 ][ 0 ] =  44 ;    m2[ 8 ][ 1 ] =  47 ;    m2[ 8 ][ 2 ] =  8 ;     m2[ 8 ][ 3 ] =  48 ;    m2[ 8 ][ 4 ] =  0 ;     m2[ 8 ][ 5 ] =  12 ;    m2[ 8 ][ 6 ] =  33 ; m2[ 8 ][ 7 ] =  48 ;    m2[ 8 ][ 8 ] =  7 ;     m2[ 8 ][ 9 ] =  41 ;    m2[ 8 ][ 10 ] =  22 ;   m2[ 8 ][ 11 ] =  10 ;   m2[ 8 ][ 12 ] =  15 ;        m2[ 8 ][ 13 ] =  2 ;    m2[ 8 ][ 14 ] =  44 ;   m2[ 8 ][ 15 ] =  42 ;   m2[ 8 ][ 16 ] =  32 ;   m2[ 8 ][ 17 ] =  24 ;   m2[ 8 ][ 18 ] =  20 ;        m2[ 8 ][ 19 ] =  36 ;
    m2[ 9 ][ 0 ] =  36 ;    m2[ 9 ][ 1 ] =  23 ;    m2[ 9 ][ 2 ] =  3 ;     m2[ 9 ][ 3 ] =  7 ;     m2[ 9 ][ 4 ] =  45 ;    m2[ 9 ][ 5 ] =  26 ;    m2[ 9 ][ 6 ] =  35 ; m2[ 9 ][ 7 ] =  22 ;    m2[ 9 ][ 8 ] =  19 ;    m2[ 9 ][ 9 ] =  19 ;    m2[ 9 ][ 10 ] =  45 ;   m2[ 9 ][ 11 ] =  44 ;   m2[ 9 ][ 12 ] =  29 ;        m2[ 9 ][ 13 ] =  30 ;   m2[ 9 ][ 14 ] =  40 ;   m2[ 9 ][ 15 ] =  45 ;   m2[ 9 ][ 16 ] =  46 ;   m2[ 9 ][ 17 ] =  36 ;   m2[ 9 ][ 18 ] =  17 ;        m2[ 9 ][ 19 ] =  20 ;
    m2[ 10 ][ 0 ] =  27 ;   m2[ 10 ][ 1 ] =  30 ;   m2[ 10 ][ 2 ] =  48 ;   m2[ 10 ][ 3 ] =  29 ;   m2[ 10 ][ 4 ] =  42 ;   m2[ 10 ][ 5 ] =  34 ;   m2[ 10 ][ 6 ] =  2 ; m2[ 10 ][ 7 ] =  11 ;   m2[ 10 ][ 8 ] =  0 ;    m2[ 10 ][ 9 ] =  0 ;    m2[ 10 ][ 10 ] =  29 ;  m2[ 10 ][ 11 ] =  25 ;  m2[ 10 ][ 12 ] =  42 ;       m2[ 10 ][ 13 ] =  32 ;  m2[ 10 ][ 14 ] =  36 ;  m2[ 10 ][ 15 ] =  45 ;  m2[ 10 ][ 16 ] =  43 ;  m2[ 10 ][ 17 ] =  48 ;  m2[ 10 ][ 18 ] =  11 ;       m2[ 10 ][ 19 ] =  6 ;
    m2[ 11 ][ 0 ] =  29 ;   m2[ 11 ][ 1 ] =  40 ;   m2[ 11 ][ 2 ] =  22 ;   m2[ 11 ][ 3 ] =  2 ;    m2[ 11 ][ 4 ] =  28 ;   m2[ 11 ][ 5 ] =  16 ;   m2[ 11 ][ 6 ] =  44 ;        m2[ 11 ][ 7 ] =  10 ;   m2[ 11 ][ 8 ] =  37 ;   m2[ 11 ][ 9 ] =  15 ;   m2[ 11 ][ 10 ] =  33 ;  m2[ 11 ][ 11 ] =  48 ;  m2[ 11 ][ 12 ] =  31 ;       m2[ 11 ][ 13 ] =  18 ;  m2[ 11 ][ 14 ] =  36 ;  m2[ 11 ][ 15 ] =  10 ;  m2[ 11 ][ 16 ] =  38 ;  m2[ 11 ][ 17 ] =  30 ;  m2[ 11 ][ 18 ] =  26 ;       m2[ 11 ][ 19 ] =  31 ;
    m2[ 12 ][ 0 ] =  16 ;   m2[ 12 ][ 1 ] =  12 ;   m2[ 12 ][ 2 ] =  30 ;   m2[ 12 ][ 3 ] =  6 ;    m2[ 12 ][ 4 ] =  9 ;    m2[ 12 ][ 5 ] =  14 ;   m2[ 12 ][ 6 ] =  33 ;        m2[ 12 ][ 7 ] =  0 ;    m2[ 12 ][ 8 ] =  10 ;   m2[ 12 ][ 9 ] =  35 ;   m2[ 12 ][ 10 ] =  8 ;   m2[ 12 ][ 11 ] =  24 ;  m2[ 12 ][ 12 ] =  12 ;       m2[ 12 ][ 13 ] =  38 ;  m2[ 12 ][ 14 ] =  3 ;   m2[ 12 ][ 15 ] =  44 ;  m2[ 12 ][ 16 ] =  34 ;  m2[ 12 ][ 17 ] =  20 ;  m2[ 12 ][ 18 ] =  9 ;        m2[ 12 ][ 19 ] =  42 ;
    m2[ 13 ][ 0 ] =  39 ;   m2[ 13 ][ 1 ] =  47 ;   m2[ 13 ][ 2 ] =  32 ;   m2[ 13 ][ 3 ] =  39 ;   m2[ 13 ][ 4 ] =  40 ;   m2[ 13 ][ 5 ] =  2 ;    m2[ 13 ][ 6 ] =  28 ;        m2[ 13 ][ 7 ] =  36 ;   m2[ 13 ][ 8 ] =  20 ;   m2[ 13 ][ 9 ] =  9 ;    m2[ 13 ][ 10 ] =  21 ;  m2[ 13 ][ 11 ] =  3 ;   m2[ 13 ][ 12 ] =  44 ;       m2[ 13 ][ 13 ] =  39 ;  m2[ 13 ][ 14 ] =  6 ;   m2[ 13 ][ 15 ] =  32 ;  m2[ 13 ][ 16 ] =  48 ;  m2[ 13 ][ 17 ] =  1 ;   m2[ 13 ][ 18 ] =  19 ;       m2[ 13 ][ 19 ] =  28 ;
    m2[ 14 ][ 0 ] =  11 ;   m2[ 14 ][ 1 ] =  26 ;   m2[ 14 ][ 2 ] =  18 ;   m2[ 14 ][ 3 ] =  33 ;   m2[ 14 ][ 4 ] =  50 ;   m2[ 14 ][ 5 ] =  46 ;   m2[ 14 ][ 6 ] =  4 ; m2[ 14 ][ 7 ] =  45 ;   m2[ 14 ][ 8 ] =  10 ;   m2[ 14 ][ 9 ] =  16 ;   m2[ 14 ][ 10 ] =  34 ;  m2[ 14 ][ 11 ] =  16 ;  m2[ 14 ][ 12 ] =  47 ;       m2[ 14 ][ 13 ] =  5 ;   m2[ 14 ][ 14 ] =  3 ;   m2[ 14 ][ 15 ] =  25 ;  m2[ 14 ][ 16 ] =  40 ;  m2[ 14 ][ 17 ] =  41 ;  m2[ 14 ][ 18 ] =  23 ;       m2[ 14 ][ 19 ] =  50 ;
    m2[ 15 ][ 0 ] =  45 ;   m2[ 15 ][ 1 ] =  13 ;   m2[ 15 ][ 2 ] =  50 ;   m2[ 15 ][ 3 ] =  19 ;   m2[ 15 ][ 4 ] =  37 ;   m2[ 15 ][ 5 ] =  29 ;   m2[ 15 ][ 6 ] =  26 ;        m2[ 15 ][ 7 ] =  31 ;   m2[ 15 ][ 8 ] =  46 ;   m2[ 15 ][ 9 ] =  50 ;   m2[ 15 ][ 10 ] =  41 ;  m2[ 15 ][ 11 ] =  29 ;  m2[ 15 ][ 12 ] =  46 ;       m2[ 15 ][ 13 ] =  50 ;  m2[ 15 ][ 14 ] =  30 ;  m2[ 15 ][ 15 ] =  10 ;  m2[ 15 ][ 16 ] =  27 ;  m2[ 15 ][ 17 ] =  45 ;  m2[ 15 ][ 18 ] =  29 ;       m2[ 15 ][ 19 ] =  42 ;
    m2[ 16 ][ 0 ] =  28 ;   m2[ 16 ][ 1 ] =  44 ;   m2[ 16 ][ 2 ] =  4 ;    m2[ 16 ][ 3 ] =  4 ;    m2[ 16 ][ 4 ] =  2 ;    m2[ 16 ][ 5 ] =  31 ;   m2[ 16 ][ 6 ] =  37 ;        m2[ 16 ][ 7 ] =  15 ;   m2[ 16 ][ 8 ] =  2 ;    m2[ 16 ][ 9 ] =  17 ;   m2[ 16 ][ 10 ] =  26 ;  m2[ 16 ][ 11 ] =  23 ;  m2[ 16 ][ 12 ] =  15 ;       m2[ 16 ][ 13 ] =  19 ;  m2[ 16 ][ 14 ] =  38 ;  m2[ 16 ][ 15 ] =  29 ;  m2[ 16 ][ 16 ] =  20 ;  m2[ 16 ][ 17 ] =  16 ;  m2[ 16 ][ 18 ] =  40 ;       m2[ 16 ][ 19 ] =  34 ;
    m2[ 17 ][ 0 ] =  29 ;   m2[ 17 ][ 1 ] =  41 ;   m2[ 17 ][ 2 ] =  27 ;   m2[ 17 ][ 3 ] =  25 ;   m2[ 17 ][ 4 ] =  49 ;   m2[ 17 ][ 5 ] =  35 ;   m2[ 17 ][ 6 ] =  1 ; m2[ 17 ][ 7 ] =  9 ;    m2[ 17 ][ 8 ] =  9 ;    m2[ 17 ][ 9 ] =  36 ;   m2[ 17 ][ 10 ] =  18 ;  m2[ 17 ][ 11 ] =  28 ;  m2[ 17 ][ 12 ] =  6 ;        m2[ 17 ][ 13 ] =  30 ;  m2[ 17 ][ 14 ] =  29 ;  m2[ 17 ][ 15 ] =  19 ;  m2[ 17 ][ 16 ] =  45 ;  m2[ 17 ][ 17 ] =  27 ;  m2[ 17 ][ 18 ] =  41 ;       m2[ 17 ][ 19 ] =  14 ;
    m2[ 18 ][ 0 ] =  45 ;   m2[ 18 ][ 1 ] =  0 ;    m2[ 18 ][ 2 ] =  45 ;   m2[ 18 ][ 3 ] =  48 ;   m2[ 18 ][ 4 ] =  16 ;   m2[ 18 ][ 5 ] =  33 ;   m2[ 18 ][ 6 ] =  32 ;        m2[ 18 ][ 7 ] =  7 ;    m2[ 18 ][ 8 ] =  3 ;    m2[ 18 ][ 9 ] =  35 ;   m2[ 18 ][ 10 ] =  50 ;  m2[ 18 ][ 11 ] =  11 ;  m2[ 18 ][ 12 ] =  38 ;       m2[ 18 ][ 13 ] =  47 ;  m2[ 18 ][ 14 ] =  16 ;  m2[ 18 ][ 15 ] =  38 ;  m2[ 18 ][ 16 ] =  34 ;  m2[ 18 ][ 17 ] =  11 ;  m2[ 18 ][ 18 ] =  4 ;        m2[ 18 ][ 19 ] =  16 ;
    m2[ 19 ][ 0 ] =  6 ;    m2[ 19 ][ 1 ] =  1 ;    m2[ 19 ][ 2 ] =  8 ;    m2[ 19 ][ 3 ] =  6 ;    m2[ 19 ][ 4 ] =  38 ;   m2[ 19 ][ 5 ] =  2 ;    m2[ 19 ][ 6 ] =  8 ; m2[ 19 ][ 7 ] =  19 ;   m2[ 19 ][ 8 ] =  7 ;    m2[ 19 ][ 9 ] =  20 ;   m2[ 19 ][ 10 ] =  24 ;  m2[ 19 ][ 11 ] =  7 ;   m2[ 19 ][ 12 ] =  7 ;        m2[ 19 ][ 13 ] =  27 ;  m2[ 19 ][ 14 ] =  37 ;  m2[ 19 ][ 15 ] =  40 ;  m2[ 19 ][ 16 ] =  29 ;  m2[ 19 ][ 17 ] =  24 ;  m2[ 19 ][ 18 ] =  36 ;       m2[ 19 ][ 19 ] =  21 ;

    int i, j;
    for(i = 0; i < 20; i++) {
        for(j = 0; j < 20; j++) {
            mr[i][j] = m1[i][j] * m2[j][i];
        }
    }

}

void Java_br_usp_benchdroid_app_benchmark_CBenchmark_fft(JNIEnv* env, jobject self) {
    // TODO
    jstring example = (*env)->NewStringUTF(env, "This is how you create a Java String!");
}
