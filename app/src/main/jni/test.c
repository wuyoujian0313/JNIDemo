//
// Created by Wu YouJian on 2019/1/18.
//


#include <jni.h>
#include <stdio.h>
#include <android/log.h>
#include <malloc.h>
#include "wuyj_com_jnidemo_JNITest.h"

#define  TAG    "test"
// 定义info信息
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__)
// 定义debug信息
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
// 定义error信息
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)


jmethodID getMethodId(JNIEnv * env, char* methodname, char* signname) {
    jclass jclazz = (*env)->FindClass(env, "wuyj/com/jnidemo/JNITest");
    if (jclazz == 0) {
        LOGD("class not find ");
        return NULL;
    }

	//2、找class中方法的id,第三个参数方法名称，第四个参数该方法对应的签名
	jmethodID methodid = (*env)->GetMethodID(env, jclazz, methodname, signname);
    if (methodid == 0) {
        LOGD("method not find ");
        return NULL;
    }
    return methodid;
}

JNIEXPORT jstring JNICALL Java_wuyj_com_jnidemo_JNITest_get
  (JNIEnv *env, jobject thiz) {

    //jclass jclazz = (*env)->FindClass(env,"wuyj/com/jnidemo/JNITest");
    jclass jclazz = (*env)->GetObjectClass(env,thiz);
    LOGD("find class class ");
    if(jclazz==0) {
        LOGD("class not find ");
        return "";
    }
    jmethodID methodid = (*env)->GetMethodID(env, jclazz,"helloFromJava","()V");
    if(methodid==0) {
        LOGD("helloFromJava method not find ");
        return "";
    }
    //创建一个CallbackJava对象
   // jobject jobj =(*env)->AllocObject(env, jclazz);
    (*env)->CallVoidMethod(env,thiz,methodid);

    return (*env)->NewStringUTF(env,"This is my first NDK Application");
}

JNIEXPORT void JNICALL Java_wuyj_com_jnidemo_JNITest_callHelloFromJava
(JNIEnv * env, jobject obj) {
    //1、 找java中的class文件
    //第二个参数是类名的（包名）
    //jclass jclazz = (*env)->FindClass(env,"wuyj/com/jnidemo/JNITest");
    jclass jclazz = (*env)->GetObjectClass(env,thiz);
    if(jclazz==0) {
        LOGD("class not find ");
        return;
    }
    //2、找class中方法的id,第三个参数方法名称，第四个参数该方法对应的签名
    jmethodID methodid = (*env)->GetMethodID(env, jclazz,"helloFromJava","()V");
    if(methodid==0) {
        LOGD("helloFromJava method not find ");
        return;
    }
    //3、调用方法
    //void (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    (*env)->CallVoidMethod(env,obj,methodid);
}

JNIEXPORT void JNICALL Java_wuyj_com_jnidemo_JNITest_callAdd
(JNIEnv *env, jobject obj) {
    jmethodID mid = getMethodId(env,"Add","(II)I");
    int result = (*env)->CallIntMethod(env, obj, mid,3,6);
    LOGD("c to java add: %d",result);
}

JNIEXPORT void JNICALL Java_wuyj_com_jnidemo_JNITest_callPrintString
(JNIEnv *env, jobject obj) {
    LOGD("c to java callPrintString start ");
    jmethodID mid = getMethodId(env,"printString","(Ljava/lang/String;)V");
    (*env)->CallVoidMethod(env, obj, mid,(*env)->NewStringUTF(env," call printString finish"));
    LOGD("c to java callPrintString finish ");
}

JNIEXPORT void JNICALL Java_wuyj_com_jnidemo_JNITest_callPrintStaticStr
(JNIEnv *env, jobject obj) {
    //jclass jclazz = (*env)->FindClass(env, "wuyj/com/jnidemo/JNITest");
    jclass jclazz = (*env)->GetObjectClass(env,thiz);
    if (jclazz == 0) {
        LOGD("class not find ");
        return;
    }
    //静态方法调用GetStaticMethodID 和 CallStaticXXXMethod
    jmethodID methodid = (*env)->GetStaticMethodID(env, jclazz, "printStaticStr", "(Ljava/lang/String;)V");
    if (methodid == 0) {
        LOGD("printStaticStr method not find ");
        return;
    }
    (*env)->CallStaticVoidMethod(env, jclazz, methodid,(*env)->NewStringUTF(env,"static hello java"));

}