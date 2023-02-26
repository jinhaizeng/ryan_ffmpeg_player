//
// Created by Ryan on 2023/2/16.
//

#ifndef RYAN_FFMPEG_PLAYER_FFMEDIAPLAYER_H
#define RYAN_FFMPEG_PLAYER_FFMEDIAPLAYER_H

#include "FFMediaConfig.h"
#include <string>
#include <JniBase.h>

extern "C" {
#include <libavformat/avformat.h>
}

using namespace std;
class FFMediaPlayer {
public:
    FFMediaConfig ffMediaConfig;
    AVFormatContext *pFormatCtx;
public:
    void setDataSource(const char* dataSource);
    const char* getDataSource();
    void init();
    int stream_open();

};


#endif //RYAN_FFMPEG_PLAYER_FFMEDIAPLAYER_H
