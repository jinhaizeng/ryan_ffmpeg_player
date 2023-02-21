//
// Created by Ryan on 2023/2/9.
// 这个函数对应了java层ryan_ffmpeg_player.media.FFMediaPlayer_java，loadClass时创建全局引用
// 这样就可以在jni层通过***随时拿到编/解码器的内容
//

#include "FFMedialPlayer_java.h"

typedef struct Java_ryan_ffmpeg_player_media_FFMediaPlayer {
    jclass classId;
    // FFmpeg播放相关 对象的地址
    jfieldID mNativeMediaPlayer_fieldId;
};

static Java_ryan_ffmpeg_player_media_FFMediaPlayer class_Java_ryan_ffmpeg_player_media_FFMediaPlayer;

void set_Java_ryan_ffmpeg_player_media_FFMediaPlaye_mNativeMediaPlayer(JNIEnv *env, jobject ref, jlong value) {
    env->SetLongField(ref, class_Java_ryan_ffmpeg_player_media_FFMediaPlayer.mNativeMediaPlayer_fieldId, value);
}

long get_Java_ryan_ffmpeg_player_media_FFMediaPlaye_mNativeMediaPlayer(JNIEnv *env, jobject ref) {
    return env->GetLongField(ref, class_Java_ryan_ffmpeg_player_media_FFMediaPlayer.mNativeMediaPlayer_fieldId);
}

int loadClass_Java_ryan_ffmpeg_player_media_FFMediaPlayer(JNIEnv *env) {
    int ret = -1;
    // jni已经映射过类了，不需要重复映射
    if (class_Java_ryan_ffmpeg_player_media_FFMediaPlayer.classId != NULL)
        return 0;
    jclass classId = env->FindClass(
            "ryan_ffmpeg_player/media/FFMediaPlayer");
    // 保存为全局引用，减少重复引用
    jclass global_classId = static_cast<jclass>(env->NewGlobalRef(classId));

    class_Java_ryan_ffmpeg_player_media_FFMediaPlayer.classId = global_classId;
    if (global_classId == NULL)
        goto fail;

    class_Java_ryan_ffmpeg_player_media_FFMediaPlayer.mNativeMediaPlayer_fieldId = env->GetFieldID(
            global_classId, "mNativeMediaPlayer", "J");


    fail:
    return ret;
}
