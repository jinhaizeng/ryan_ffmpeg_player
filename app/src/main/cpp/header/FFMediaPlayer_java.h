//
// Created by Ryan on 2023/2/2.
//
#include "./utils.h"
#include "./ff_player.h"

#ifndef RYAN_FFMPEG_PLAYER_FFMEDIAPLAYER_H
#define RYAN_FFMPEG_PLAYER_FFMEDIAPLAYER_H

struct FFMediaPlayer_java {
    AVFormatContext *pFormatCtx;
};

typedef struct FFMediaPlayer_java FFMediaPlayer;

#endif //RYAN_FFMPEG_PLAYER_FFMEDIAPLAYER_H


