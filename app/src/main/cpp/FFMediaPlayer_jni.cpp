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
#include <FFMedialPlayer_java.h>
#include <FFMediaPlayer.h>
#include <string>
#include "libSDL2/SDL_thread.h"

#define LOGI(FORMAT, ...) __android_log_print(ANDROID_LOG_INFO,"ryan_test",FORMAT,##__VA_ARGS__);
#define LOGE(FORMAT, ...) __android_log_print(ANDROID_LOG_ERROR,"ryan_test",FORMAT,##__VA_ARGS__);

//
// Created by Ryan on 2023/2/2.
//

int my_thread( void *data )
{
    //当程序还未结束
    LOGE("Hello from C++");

    return 0;
}
extern "C" JNIEXPORT void JNICALL
Java_ryan_1ffmpeg_1player_media_FFMediaPlayer__1native_1setup(JNIEnv *env, jobject jObject) {

    SDL_CreateThread(my_thread, "my_thread", NULL);

    loadClass_FFMediaPlayer(env);
    FFMediaPlayer player;
    // weakRef这里为什么要用弱引用
    set_mNativeMediaPlayer(env, jObject, reinterpret_cast<jlong>(&player));
}

extern "C" JNIEXPORT void JNICALL
Java_ryan_1ffmpeg_1player_media_FFMediaPlayer__1init(JNIEnv *env, jobject jObject) {
    // 暂时不做任何处理
//    loadClass_FFMediaPlayer(env);
//    const char *filePathStr = (*env)->GetStringUTFChars(env, filePath, NULL);
    // 封装格式上下文，统领全局的结构体，保存了视频文件封装格式的相关信息
//    FFMediaPlayer_java *pFFMediaPlayer = (FFMediaPlayer_java*)mallocz(sizeof(FFMediaPlayer_java));
//    avformat_init(&pFFMediaPlayer->pFormatCtx, filePathStr);
}

JNIEXPORT void JNICALL
Java_ryan_1ffmpeg_1player_media_FFMediaPlayer__1setDataSource(JNIEnv *env, jobject jObject,
                                                              jstring jDataSource) {
    FFMediaPlayer *pPlayer = reinterpret_cast<FFMediaPlayer *>(get_mNativeMediaPlayer(env,
                                                                                      jObject));
    const char *dataSource = env->GetStringUTFChars(jDataSource, NULL);
    pPlayer->setDataSource(strdup(dataSource));
    env->ReleaseStringUTFChars(jDataSource, dataSource);
}

extern "C" JNIEXPORT void JNICALL
Java_ryan_1ffmpeg_1player_media_FFMediaPlayer__1prepare(JNIEnv *env, jobject jObject) {
    // 初始化播放器相关内容
    FFMediaPlayer *player = reinterpret_cast<FFMediaPlayer *>(get_mNativeMediaPlayer(env, jObject));
    player->stream_open();
}



extern "C" JNIEXPORT void JNICALL
Java_ryan_1ffmpeg_1player_media_FFMediaPlayer__1unInit(JNIEnv *env, jobject jObject) {
    // 主要就是释放malloc申请过的内存
//    avformat_uninit();
}

extern "C" JNIEXPORT void JNICALL
Java_ryan_1ffmpeg_1player_media_FFMediaPlayer__1destory(JNIEnv *env, jobject jObject) {
    FFMediaPlayer *pPlayer = reinterpret_cast<FFMediaPlayer *>(get_mNativeMediaPlayer(env,
                                                                                      jObject));
    // 释放掉strdup复制过的内容
    free((void *) pPlayer->getDataSource());
}