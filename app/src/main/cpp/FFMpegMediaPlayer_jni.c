//
// Created by Ryan on 2023/2/5.
//

#include "header/FFMpegMediaPlayer_jni.h"

typedef struct FFmpegMediaPlayer {
    jclass id;
    jfieldID  field_mNativeMediaPlayer;
} FFmpegMediaPlayer;

static FFmpegMediaPlayer ffmpegMediaPlayer;
int load_FFmpegMediaPlayer_class(JNIEnv *env){
    int ret = -1;
    const char *name = NULL;
    const char *sign = NULL;
    jclass class_id = NULL;
    int api_level = 0;

    if (ffmpegMediaPlayer.id != NULL)
        return 0;
    // java文件夹下的包名路径
    sign = "com/example/ryan_ffmpeg_player/Media/FFmpegMediaPlayer";
//    ffmpegMediaPlayer.id =

}
