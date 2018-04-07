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
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_alan_alanjni_JNIWrapper_nativeSetArgString
        (JNIEnv *env, jobject obj, jstring strArg) {

    // 当 isCopy 为 JNI_TRU E时，表示返回源字符串的一个副本；
    // 当其为 JNI_FALSE 表示直接返回源字符串的指针；
    // 如果不关心返回的是一个实例还是一个指向源字符串的指针，可以为NULL;
    jboolean iscopy;

    // 这里不能直接使用 strArg，需要将其通过 GetStringUTFChars 接口将其转成 UTF-8 的 字符串的指针
    char *cStr = (char *) env->GetStringUTFChars(strArg, &iscopy);
    LOGD(TAG_JNI, "nativeSetArgString()--->cStr = %s", cStr);

    // 最后需要释放，否则可能导致内存泄漏
    env->ReleaseStringUTFChars(strArg, cStr);

    // 向上层返回 string
    char cChars[] = "The String is from native!";
    return env->NewStringUTF(cChars);
}


/*
 * Class:     com_alan_alanjni_JNIWrapper
 * Method:    nativeSetArgFieldInfo
 * Signature: (Lcom/alan/alanjni/beans/ArgInfo;)V
 */
JNIEXPORT void JNICALL Java_com_alan_alanjni_JNIWrapper_nativeSetArgFieldInfo
        (JNIEnv *env, jobject obj, jobject jArgObj) {

    jfieldID fieldID = NULL;
    // 根据参数对象获取 class，下面可以从 class 中获取 FieldID 或 MethodID
    jclass infoClass = env->GetObjectClass(jArgObj);

    // 通过属性变量名（跟 java 中定义的变量名一致，如 booleanArg）和变量类型签名（boolean 的类型签名是 Z），获取 FieldID
    fieldID = env->GetFieldID(infoClass, "booleanArg", "Z");
    jboolean booleanArg = (jboolean) env->GetBooleanField(jArgObj, fieldID);
    LOGD(TAG_JNI, "nativeSetArgFieldInfo()--->booleanArg = %d", booleanArg);

    // 获取 ArgInfo 中定义的 byteArg 变量的 FieldID，byte 型的类型签名是 B
    fieldID = env->GetFieldID(infoClass, "byteArg", "B");
    jbyte byteArg = (jbyte) env->GetByteField(jArgObj, fieldID);
    LOGD(TAG_JNI, "nativeSetArgFieldInfo()--->byteArg = %d", byteArg);

    // 获取 ArgInfo 中定义的 charArg 变量的 FieldID，char 型的类型签名是 C
    fieldID = env->GetFieldID(infoClass, "charArg", "C");
    jchar charArg = (jchar) env->GetCharField(jArgObj, fieldID);
    LOGD(TAG_JNI, "nativeSetArgFieldInfo()--->charArg = %c", charArg);

    // 获取 ArgInfo 中定义的 shortArg 变量的 FieldID，short 型的类型签名是 S
    fieldID = env->GetFieldID(infoClass, "shortArg", "S");
    jshort shortArg = (jshort) env->GetShortField(jArgObj, fieldID);
    LOGD(TAG_JNI, "nativeSetArgFieldInfo()--->shortArg = %d", shortArg);

    // 获取 ArgInfo 中定义的 intArg 变量的 FieldID，int 型的类型签名是 I
    fieldID = env->GetFieldID(infoClass, "intArg", "I");
    jint intArg = (jint) env->GetIntField(jArgObj, fieldID);
    LOGD(TAG_JNI, "nativeSetArgFieldInfo()--->intArg = %d", intArg);

    // 获取 ArgInfo 中定义的 longArg 变量的 FieldID，long 型的类型签名是 J
    fieldID = env->GetFieldID(infoClass, "longArg", "J");
    jlong longArg = (jlong) env->GetLongField(jArgObj, fieldID);
    LOGD(TAG_JNI, "nativeSetArgFieldInfo()--->longArg = %ld", longArg);

    // 获取 ArgInfo 中定义的 floatArg 变量的 FieldID，float 型的类型签名是 F
    fieldID = env->GetFieldID(infoClass, "floatArg", "F");
    jfloat floatArg = (jfloat) env->GetFloatField(jArgObj, fieldID);
    LOGD(TAG_JNI, "nativeSetArgFieldInfo()--->floatArg = %f", floatArg);

    // 获取 ArgInfo 中定义的 intArg 变量的 FieldID，double 型的类型签名是 D
    fieldID = env->GetFieldID(infoClass, "doubleArg", "D");
    jdouble doubleArg = (jdouble) env->GetDoubleField(jArgObj, fieldID);
    LOGD(TAG_JNI, "nativeSetArgFieldInfo()--->doubleArg = %f", doubleArg);

    // 获取 ArgInfo 中定义的 strArg 变量的 FieldID，OtherInfo 型的类型签名是 Ljava/lang/String;
    fieldID = env->GetFieldID(infoClass, "strArg", "Ljava/lang/String;");
    jstring strArg = (jstring) env->GetObjectField(jArgObj, fieldID);

    char *cStr = (char *) env->GetStringUTFChars(strArg, NULL);
    LOGD(TAG_JNI, "nativeSetArgFieldInfo()--->cStr = %s", cStr);
    // 最后需要释放，否则可能导致内存泄漏
    env->ReleaseStringUTFChars(strArg, cStr);


    // 以下是获取自定义对象中的自定义对象，即 ArgInfo 类中声明的 OtherInfo 属性变量
    // 获取 ArgInfo 中定义的 infoArg 变量的 FieldID，
    // 自定义对象的签名是 L<类的带包名全路径>;
    // OtherInfo 型的类型签名是 Lcom/alan/alanjni/beans/OtherInfo; (记得末尾有分号)
    fieldID = env->GetFieldID(infoClass, "infoArg", "Lcom/alan/alanjni/beans/OtherInfo;");
    jobject infoArg = (jobject) env->GetObjectField(jArgObj, fieldID);

    //获取子自定义对象的 class
    jclass subArgClass = env->GetObjectClass(infoArg);
    // 获取子自定义对象中的属性变量，可见 java 中的 OtherInfo 类
    jfieldID subFieldID = env->GetFieldID(subArgClass, "intInfo", "I");
    jint intInfo = env->GetIntField(infoArg, subFieldID);
    LOGD(TAG_JNI, "nativeSetArgFieldInfo()--->infoArg.intInfo = %d", intInfo);

}