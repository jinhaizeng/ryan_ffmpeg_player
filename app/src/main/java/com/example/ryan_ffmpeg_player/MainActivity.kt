package com.example.ryan_ffmpeg_player

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Environment
import android.util.Log
import android.widget.TextView
import com.example.ryan_ffmpeg_player.Constant.TAG
import com.example.ryan_ffmpeg_player.databinding.ActivityMainBinding
import java.io.File

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
//        binding.sampleText.text = stringFromJNI()
    }

    override fun onResume() {
        super.onResume()
        decode();
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
        val fileName = "share_fe91b7596d0f78b5089dd5ba1c946bce.mp4";
        val input = File(
            path,
            fileName
        ).absolutePath
        Log.e(TAG, "path" + Environment.getExternalStorageDirectory())

        val output = File(
            path,
             "share_fe91b7596d0f78b5089dd5ba1c946bce_output_1280x720_yuv420p.yuv"
        ).absolutePath

        Log.e(TAG, "input = $input ${File(input).exists()}")

        VideoUtil.decode(input, output)
    }
}