package ryan_ffmpeg_player;

import ryan_ffmpeg_player.media.FFMediaPlayer;

public class VideoUtil {
    static {
        // 下面的都是 ffmpeg 的依赖库，这里的库是有顺序要求的
        System.loadLibrary("avutil");
        System.loadLibrary("swresample");
        System.loadLibrary("avcodec");
        System.loadLibrary("avformat");
        System.loadLibrary("swscale");
        System.loadLibrary("postproc");
        System.loadLibrary("avfilter");
        System.loadLibrary("avdevice");

        // 这个是我们自己 CMakeLists.txt 脚本编译生成的库
        System.loadLibrary("ryan_ffmpeg_player");

//        System.loadLibrary("ryan_ffmepg_player");
    }

    public void testThread() {
        new FFMediaPlayer().native_setup();
    }

}