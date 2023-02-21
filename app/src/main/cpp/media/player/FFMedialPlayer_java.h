//
// Created by Ryan on 2023/2/9.
//

#ifndef RYAN_FFMPEG_PLAYER_FFMEDIALPLAYER_JAVA_H
#define RYAN_FFMPEG_PLAYER_FFMEDIALPLAYER_JAVA_H

#include <jni.h>

void set_Java_ryan_ffmpeg_player_media_FFMediaPlaye_mNativeMediaPlayer(JNIEnv *env, jobject weakRef, jlong value);
long get_Java_ryan_ffmpeg_player_media_FFMediaPlaye_mNativeMediaPlayer(JNIEnv *env, jobject weakRef);
int loadClass_Java_ryan_ffmpeg_player_media_FFMediaPlayer(JNIEnv *env);

#define set_mNativeMediaPlayer set_Java_ryan_ffmpeg_player_media_FFMediaPlaye_mNativeMediaPlayer
#define get_mNativeMediaPlayer get_Java_ryan_ffmpeg_player_media_FFMediaPlaye_mNativeMediaPlayer
#define loadClass_FFMediaPlayer loadClass_Java_ryan_ffmpeg_player_media_FFMediaPlayer

#endif //RYAN_FFMPEG_PLAYER_FFMEDIALPLAYER_JAVA_H
