package ryan_ffmpeg_player.media;

import java.lang.ref.WeakReference;

public class FFMediaPlayer {
    private long mNativeMediaPlayer;

    public native void native_setup();

    public native void _init();

    public native void _setDataSource();

    public native void _prepare();

    public native void _unInit();

    public native void _destory();

    public void prepare() {
        this.prepare();
    }
}
