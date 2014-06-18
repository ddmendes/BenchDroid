#include <string.h>
#include <jni.h>

void Java_br_usp_benchdroid_app_benchmark_CBenchmark_superSwap(JNIEnv* env, jobject self) {
    const int limit = 1000*1000*1000; // One billion!
    int a = 10;
    int b = 0;
    int i, temp;
    for (i = 0; i < limit; i++) {
        temp = a;
        a = b;
        b = temp;
    }
}

void Java_br_usp_benchdroid_app_benchmark_CBenchmark_pi(JNIEnv* env, jobject self) {
    // TODO
    jstring example = (*env)->NewStringUTF(env, "This is how you create a Java String!");
}

void Java_br_usp_benchdroid_app_benchmark_CBenchmark_multMatrix(JNIEnv* env, jobject self) {
    // TODO
}
