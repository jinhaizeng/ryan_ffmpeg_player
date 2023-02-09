package ryan_ffmpeg_player;

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

    /**
     * 当前方法是 jni 方法，在这里声明，需要取 c/c++ 中实现
     *
     * 视频解码
     * @param input 需要解码的视频路径，例如：/xxx.mp4
     * @param output 解码后的，视频保村路径，例如：/xxx.yuv
     */
    public native static void decode(String input, String output);

    public native static void helloNDK();

}