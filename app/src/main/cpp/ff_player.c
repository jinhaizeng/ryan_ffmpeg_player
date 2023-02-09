//
// Created by Ryan on 2023/2/2.
//

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

#define LOGI(FORMAT, ...) __android_log_print(ANDROID_LOG_INFO,"ryan_test",FORMAT,##__VA_ARGS__);
#define LOGE(FORMAT, ...) __android_log_print(ANDROID_LOG_ERROR,"ryan_test",FORMAT,##__VA_ARGS__);

/**
 * 解封装器初始化
 */
void avformat_init(AVFormatContext **pFormatCtx, char *input_cstr){
    //封装格式上下文，统领全局的结构体，保存了视频文件封装格式的相关信息
    *pFormatCtx = avformat_alloc_context();
    //打开输入视频文件
    const int openResult = avformat_open_input(pFormatCtx, input_cstr, NULL, NULL);
    if (openResult != 0) {
        LOGE("%s%s%d", "无法打开输入视频文件", input_cstr, openResult);
        return;
    }

    //获取视频文件信息
    if (avformat_find_stream_info(*pFormatCtx, NULL) < 0) {
        LOGE("%s", "无法获取视频文件信息");
        return;
    }
    LOGE("%s", "解封装器初始化--成功");
}

/**
 * 解封器反初始化
 */
void avformat_uninit(AVFormatContext **pFormatCtx){
    avformat_free_context(*pFormatCtx);
}