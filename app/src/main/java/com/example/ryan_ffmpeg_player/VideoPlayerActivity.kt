package com.example.ryan_ffmpeg_player

import android.net.Uri
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.Environment
import android.util.Log
import android.view.View
import android.widget.Button
import android.widget.Toast
import androidx.activity.result.contract.ActivityResultContracts
import com.example.ryan_ffmpeg_player.Constant.TAG
import com.example.ryan_ffmpeg_player.Utils.FileUtils
import java.io.File
import java.lang.Exception

class VideoPlayerActivity : AppCompatActivity(), View.OnClickListener {
    lateinit var playButton: Button
    lateinit var videoSurfaceView: VideoSurfaceView
    lateinit var albumButton: Button
    lateinit var filePath: String

    private val pickLauncher =
        registerForActivityResult(ActivityResultContracts.GetContent()) { uri: Uri? ->
            uri?.let { it ->
                filePath = FileUtils.getFilePathByUri(this, it)
                Log.d(TAG, "图片地址：" + filePath)
            }
        }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_video_player)

        PermissionUtils.requestMyPermissions(this)
        playButton = findViewById(R.id.playButton)
        videoSurfaceView = findViewById(R.id.videoView)
        albumButton = findViewById(R.id.sys_choose_image)
        playButton.setOnClickListener(this)
        albumButton.setOnClickListener(this)
    }

    override fun onResume() {
        super.onResume()
//        decode();
    }

    override fun onClick(v: View?) {
        when (v?.id) {
            R.id.playButton -> {
                if (!filePath.isEmpty()) {
                    Log.d(TAG, "输入文件路径是否正常：" + File(filePath).exists())
                    videoSurfaceView.player(filePath)
                } else {
                    Toast.makeText(this, "文件路径异常：" + filePath, Toast.LENGTH_LONG).show()
                }
            }
            R.id.sys_choose_image -> {
                // 图片选image/* 视频选video/*
                pickLauncher.launch("video/*")
            }
        }
    }

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
        if (outputFile.exists()) {
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
        Log.e(
            TAG,
            "input = $input ${File(input).exists()}, output = $output ${File(output).exists()}"
        )

        VideoUtil.decode(input, output)
        VideoUtil.helloNDK()
    }
}