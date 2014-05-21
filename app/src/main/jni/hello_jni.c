#include <string.h>
#include <jni.h>

jstring Java_br_usp_benchdroid_app_JNITest_test(JNIEnv* env, jobject self) {
    return (*env)->NewStringUTF(env, "Hello from JNI!");
}