//
// Created by Ryan on 2023/2/2.
//
#include "./utils.h"
#include "./ff_player.h"

#ifndef RYAN_FFMPEG_PLAYER_FFMEDIAPLAYER_H
#define RYAN_FFMPEG_PLAYER_FFMEDIAPLAYER_H

struct FFMediaPlayer {
    AVFormatContext *pFormatCtx;
};

typedef struct FFMediaPlayer FFMediaPlayer;

#endif //RYAN_FFMPEG_PLAYER_FFMEDIAPLAYER_H


