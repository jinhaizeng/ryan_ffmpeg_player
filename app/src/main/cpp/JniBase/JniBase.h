//
// Created by Ryan on 2023/2/5.
//

#ifndef RYAN_FFMPEG_PLAYER_JNIBASE_H
#define RYAN_FFMPEG_PLAYER_JNIBASE_H

#include <jni.h>
#include <android/log.h>
#include <stdio.h>

#define LOG_TAG "JNI_IJK"

#define J4A_ALOGV(...)  __android_log_print(ANDROID_LOG_VERBOSE,    LOG_TAG, __VA_ARGS__)
#define J4A_ALOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,      LOG_TAG, __VA_ARGS__)
#define J4A_ALOGI(...)  __android_log_print(ANDROID_LOG_INFO,       LOG_TAG, __VA_ARGS__)
#define J4A_ALOGW(...)  __android_log_print(ANDROID_LOG_WARN,       LOG_TAG, __VA_ARGS__)
#define J4A_ALOGE(...)  __android_log_print(ANDROID_LOG_ERROR,      LOG_TAG, __VA_ARGS__)
#define J4A_FUNC_FAIL_TRACE()               do {J4A_ALOGE("%s: failed\n", __func__);} while (0)
#define J4A_FUNC_FAIL_TRACE1(x__)           do {J4A_ALOGE("%s: failed: %s\n", __func__, x__);} while (0)
#define J4A_FUNC_FAIL_TRACE2(x1__, x2__)    do {J4A_ALOGE("%s: failed: %s %s\n", __func__, x1__, x2__);} while (0)

bool J4A_ExceptionCheck__throwAny(JNIEnv *env);
bool J4A_ExceptionCheck__catchAll(JNIEnv *env);
int J4A_ThrowExceptionOfClass(JNIEnv* env, jclass clazz, const char* msg);
int J4A_ThrowException(JNIEnv* env, const char* class_sign, const char* msg);
int J4A_ThrowIllegalStateException(JNIEnv *env, const char* msg);
jclass J4A_NewGlobalRef__catchAll(JNIEnv *env, jobject obj);
void J4A_DeleteLocalRef(JNIEnv *env, jobject obj);
void J4A_DeleteLocalRef__p(JNIEnv *env, jobject *obj);
void J4A_DeleteGlobalRef(JNIEnv *env, jobject obj);
void J4A_DeleteGlobalRef__p(JNIEnv *env, jobject *obj);
void J4A_ReleaseStringUTFChars(JNIEnv *env, jstring str, const char *c_str);
void J4A_ReleaseStringUTFChars__p(JNIEnv *env, jstring str, const char **c_str);
jclass J4A_FindClass__catchAll(JNIEnv *env, const char *class_sign);
jclass J4A_FindClass__asGlobalRef__catchAll(JNIEnv *env, const char *class_sign);
jmethodID J4A_GetMethodID__catchAll(JNIEnv *env, jclass clazz, const char *method_name, const char *method_sign);
jmethodID J4A_GetStaticMethodID__catchAll(JNIEnv *env, jclass clazz, const char *method_name, const char *method_sign);
jfieldID J4A_GetFieldID__catchAll(JNIEnv *env, jclass clazz, const char *field_name, const char *field_sign);
jfieldID J4A_GetStaticFieldID__catchAll(JNIEnv *env, jclass clazz, const char *field_name, const char *field_sign);
jbyteArray J4A_NewByteArray__catchAll(JNIEnv *env, jsize capacity);
jbyteArray J4A_NewByteArray__asGlobalRef__catchAll(JNIEnv *env, jsize capacity);
int J4A_GetSystemAndroidApiLevel(JNIEnv *env);

#endif //RYAN_FFMPEG_PLAYER_JNIBASE_H
