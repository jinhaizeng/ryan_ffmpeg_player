package ryan_ffmpeg_player

import android.content.Context
import android.graphics.PixelFormat
import android.util.AttributeSet
import android.view.Surface
import android.view.SurfaceHolder
import android.view.SurfaceView

class VideoSurfaceView: SurfaceView, SurfaceHolder.Callback {
    constructor(context: Context) : super(context) {}

    constructor(context: Context, attrs: AttributeSet) : super(context, attrs) {
        init()
    }

    constructor(context: Context, attrs: AttributeSet, defStyleAttr: Int) : super(context, attrs, defStyleAttr) {}

    companion object {
        init {
            // 下面的都是 ffmpeg 的依赖库，这里的库是有顺序要求的
            System.loadLibrary("avutil")
            System.loadLibrary("swresample")
            System.loadLibrary("avcodec")
            System.loadLibrary("avformat")
            System.loadLibrary("swscale")
            System.loadLibrary("postproc")
            System.loadLibrary("avfilter")
            System.loadLibrary("avdevice")

            // 这个是我们自己 CMakeLists.txt 脚本编译生成的库
            System.loadLibrary("ryan_ffmpeg_player")
        }
    }

    private fun init() {
        val holder = holder
        holder.setFormat(PixelFormat.RGBA_8888)
    }

    external fun render(input: String, surface: Surface)

    fun player(input: String) {
        Thread(Runnable {
            //        绘制功能 不需要交给SurfaveView        VideoView.this.getHolder().getSurface()
            render(input, this@VideoSurfaceView.holder.surface)
        }).start()
    }

    override fun surfaceCreated(holder: SurfaceHolder) {
        TODO("Not yet implemented")
    }

    override fun surfaceChanged(holder: SurfaceHolder, format: Int, width: Int, height: Int) {
        TODO("Not yet implemented")
    }

    override fun surfaceDestroyed(holder: SurfaceHolder) {
        TODO("Not yet implemented")
    }


}