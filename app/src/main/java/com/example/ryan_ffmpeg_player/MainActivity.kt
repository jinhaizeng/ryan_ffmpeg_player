package com.example.ryan_ffmpeg_player

import android.Manifest
import android.content.Intent
import android.content.pm.PackageManager
import android.os.Build
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Environment
import android.provider.Settings
import android.util.Log
import android.widget.TextView
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat
import com.example.ryan_ffmpeg_player.Constant.TAG
import com.example.ryan_ffmpeg_player.databinding.ActivityMainBinding
import java.io.File
import java.lang.Exception

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        PermissionUtils.requestMyPermissions(this)
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