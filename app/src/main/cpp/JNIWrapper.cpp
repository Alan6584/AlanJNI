#include <android/log.h>
#include "JNIWrapper.h"

#define LOGD(TAG, ...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define TAG_JNI "TAG_JNI"

/*
 * Class:     com_alan_alanjni_JNIWrapper
 * Method:    nativeSetArgBoolean
 * Signature: (Z)Z
 */
JNIEXPORT jboolean JNICALL Java_com_alan_alanjni_JNIWrapper_nativeSetArgBoolean
  (JNIEnv *env, jobject obj, jboolean bArg) {
    jboolean ret = !bArg; // 对传入的参数 bArg 取反
    LOGD(TAG_JNI, "nativeSetArgBoolean()--->bArg = %d, ret = %d", bArg, ret);
    return ret;
}

/*
 * Class:     com_alan_alanjni_JNIWrapper
 * Method:    nativeSetArgByte
 * Signature: (B)B
 */
JNIEXPORT jbyte JNICALL Java_com_alan_alanjni_JNIWrapper_nativeSetArgByte
  (JNIEnv *env, jobject obj, jbyte bArg) {
    jbyte ret = bArg << 2; // 对传入的 bArg 左移两位（即乘 2 ）
    LOGD(TAG_JNI, "nativeSetArgByte()--->bArg = %d, ret = %d", bArg, ret);
    return ret;
}

/*
 * Class:     com_alan_alanjni_JNIWrapper
 * Method:    nativeSetArgChar
 * Signature: (C)C
 */
JNIEXPORT jchar JNICALL Java_com_alan_alanjni_JNIWrapper_nativeSetArgChar
  (JNIEnv *env, jobject obj, jchar cArg) {
    jchar ret = cArg + 1; // 对传入的 cArg 加 1，即其下一个字符
    LOGD(TAG_JNI, "nativeSetArgChar()--->cArg = %c, ret = %c", cArg, ret);
    return ret;
}

/*
 * Class:     com_alan_alanjni_JNIWrapper
 * Method:    nativeSetArgShort
 * Signature: (S)S
 */
JNIEXPORT jshort JNICALL Java_com_alan_alanjni_JNIWrapper_nativeSetArgShort
  (JNIEnv *env, jobject obj, jshort sArg) {
    jshort ret = sArg + 2; // 对传入的参数 sArg 加 2
    LOGD(TAG_JNI, "nativeSetArgShort()--->sArg = %d, ret = %d", sArg, ret);
    return ret;
}

/*
 * Class:     com_alan_alanjni_JNIWrapper
 * Method:    nativeSetArgInt
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_alan_alanjni_JNIWrapper_nativeSetArgInt
  (JNIEnv *env, jobject obj, jint iArg) {
    jint ret;
    if (iArg < 10) {// 如果传入的参数 iArg 小于 10，则返回成功，否则返回失败
        ret = 0;
    } else {
        ret = -1;
    }
    LOGD(TAG_JNI, "nativeSetArgInt()--->iArg = %d, ret = %d", iArg, ret);
    return ret;
}

/*
 * Class:     com_alan_alanjni_JNIWrapper
 * Method:    nativeSetArgLong
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_alan_alanjni_JNIWrapper_nativeSetArgLong
  (JNIEnv *env, jobject obj, jlong lArg) {
    jlong ret = lArg + 1 * 1000 * 1000; // 对传入的 lArg 做运算
    LOGD(TAG_JNI, "nativeSetArgLong()--->lArg = %ld, ret = %ld", lArg, ret);
    return ret;
}

/*
 * Class:     com_alan_alanjni_JNIWrapper
 * Method:    nativeSetArgFloat
 * Signature: (F)D
 */
JNIEXPORT jfloat JNICALL Java_com_alan_alanjni_JNIWrapper_nativeSetArgFloat
  (JNIEnv *env, jobject obj, jfloat fArg) {
    jfloat ret = fArg + 1.0f; // 对传入的 fArg 做运算
    LOGD(TAG_JNI, "nativeSetArgFloat()--->fArg = %f, ret = %f", fArg, ret);
    return ret;
}

/*
 * Class:     com_alan_alanjni_JNIWrapper
 * Method:    nativeSetArgDouble
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_com_alan_alanjni_JNIWrapper_nativeSetArgDouble
  (JNIEnv *env, jobject obj, jdouble dArg) {
    jdouble ret = dArg + 2.0; // 对传入的 dArg 做运算
    LOGD(TAG_JNI, "nativeSetArgDouble()--->dArg = %lf, ret = %lf", dArg, ret);
    return ret;
}

/*
 * Class:     com_alan_alanjni_JNIWrapper
 * Method:    nativeSetArgString
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_alan_alanjni_JNIWrapper_nativeSetArgString
        (JNIEnv *env, jobject obj, jstring strArg) {
    jboolean iscopy;
    char *cStr = (char *) env->GetStringUTFChars(strArg, &iscopy);

    LOGD(TAG_JNI, "nativeSetArgString()--->cStr = %s", cStr);

    env->ReleaseStringUTFChars(strArg, cStr);
}
