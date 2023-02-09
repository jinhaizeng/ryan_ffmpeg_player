#include <jni.h>
#include <android/log.h>

// 编码
#include "libavcodec/avcodec.h"
// 封装格式处理
#include "libavformat/avformat.h"
// 像素处理
#include "libswscale/swscale.h"
#include <jni.h>
#include <libavutil/imgutils.h>
#include <android/native_window_jni.h>
#include <unistd.h>
#include "header/FFMediaPlayer.h"

#define LOGI(FORMAT, ...) __android_log_print(ANDROID_LOG_INFO,"ryan_test",FORMAT,##__VA_ARGS__);
#define LOGE(FORMAT, ...) __android_log_print(ANDROID_LOG_ERROR,"ryan_test",FORMAT,##__VA_ARGS__);

//
// Created by Ryan on 2023/2/2.
//

JNIEXPORT void JNICALL
Java_ryan_1ffmpeg_1player_FFPlayerEngine_init(JNIEnv *env, jclass clazz,
                                                          jstring filePath) {
    const char *filePathStr = (*env)->GetStringUTFChars(env, filePath, NULL);
    // 封装格式上下文，统领全局的结构体，保存了视频文件封装格式的相关信息
    FFMediaPlayer *pFFMediaPlayer = (FFMediaPlayer*)mallocz(sizeof(FFMediaPlayer));
    avformat_init(&pFFMediaPlayer->pFormatCtx, filePathStr);
}

JNIEXPORT void JNICALL
Java_ryan_1ffmpeg_1player_FFPlayerEngine_unInit(JNIEnv *env, jclass clazz) {
    // 主要就是释放malloc申请过的内存
//    avformat_uninit();
}

JNIEXPORT void JNICALL
Java_ryan_1ffmpeg_1player_FFPlayerEngine_streamOpen(JNIEnv *env, jclass clazz,
                                                                jstring input, jstring output) {
    // TODO: implement streamOpen()
}