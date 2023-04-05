package ryan_ffmpeg_player.media;

import java.lang.ref.WeakReference;

public class FFMediaPlayer {
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

    private long mNativeMediaPlayer;

    public native void _native_setup();

    public native void _init();

    public native void _setDataSource();

    public native void _prepare();

    public native void _unInit();

    public native void _destory();

    public void prepare() {
        this._prepare();
    }

    // 写出来测试下SDL2库能不能正常跑通
    public void native_setup() {
        this._native_setup();
    }
}
