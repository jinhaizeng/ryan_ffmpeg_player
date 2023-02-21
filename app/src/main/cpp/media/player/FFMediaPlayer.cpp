//
// Created by Ryan on 2023/2/16.
//

#include "FFMediaPlayer.h"

void FFMediaPlayer::setDataSource(const char* dataSource){
    //
    FFMediaPlayer::ffMediaConfig.dataSource = dataSource;
}

const char* FFMediaPlayer::getDataSource(){
    return FFMediaPlayer::ffMediaConfig.dataSource;
}

void FFMediaPlayer::init() {
}

int FFMediaPlayer::stream_open() {
    AVFormatContext *pFormatCtx = FFMediaPlayer::pFormatCtx;
    pFormatCtx = avformat_alloc_context();
    int ret = avformat_open_input(&pFormatCtx, FFMediaPlayer::getDataSource(), NULL, NULL);
    if (ret != 0) {
        ALOGE("avformat_open_input error, ret: %d", ret);
        return -1;
    }
    

}

