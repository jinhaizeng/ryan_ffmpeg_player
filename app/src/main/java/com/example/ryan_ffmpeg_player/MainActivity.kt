package com.example.ryan_ffmpeg_player

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Environment
import android.util.Log
import android.widget.Button
import com.example.ryan_ffmpeg_player.Constant.TAG
import java.io.File
import java.lang.Exception

class MainActivity : AppCompatActivity() {
    lateinit var playButton: Button
    lateinit var videoView: VideoView
    // TODO 这里要改下路径
    val input = File(Environment.getExternalStorageDirectory(), "DCIM/ScreenRecorder/Screenrecorder-2022-11-09-10-52-55-338.mp4").absolutePath!!

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        Log.d(TAG, "输入文件路径是否正常：" + File(input).exists())
        PermissionUtils.requestMyPermissions(this)
        playButton = findViewById(R.id.playButton)
        videoView = findViewById(R.id.videoView)
        playButton.setOnClickListener {  videoView.player(input) }
    }

    override fun onResume() {
        super.onResume()
//        decode();
    }

//    /**
//     * A native method that is implemented by the 'ryan_ffmpeg_player' native library,
//     * which is packaged with this application.
//     */
//    external fun stringFromJNI(): String

//    companion object {
//        // Used to load the 'ryan_ffmpeg_player' library on application startup.
//        init {
//            System.loadLibrary("ryan_ffmpeg_player")
//        }
//    }

    private fun decode() {
        val path = "/sdcard/DCIM/Camera";
        val fileName = "DCIM/ScreenRecorder/Screenrecorder-2022-11-09-10-52-55-338.mp4";
        val input = File(
            Environment.getExternalStorageDirectory(),
            fileName
        ).absolutePath
        Log.e(TAG, "path" + Environment.getExternalStorageDirectory())

        val output = File(
            Environment.getExternalStorageDirectory(),
             "test_yuv420p.yuv"
        ).absolutePath

        val outputFile = File(output)
        if (outputFile.exists()){
            outputFile.delete();
        }
        try {
            //创建文件
            val createResult = outputFile.createNewFile();
            //给一个吐司提示，提示创建成功
        } catch (e: Exception) {
            e.printStackTrace();
            Log.e(TAG, "output e" + e)

        }
        Log.e(TAG, "input = $input ${File(input).exists()}, output = $output ${File(output).exists()}")

        VideoUtil.decode(input, output)
        VideoUtil.helloNDK()
    }
}