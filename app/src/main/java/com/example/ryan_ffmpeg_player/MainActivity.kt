package com.example.ryan_ffmpeg_player

import android.content.Intent
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

class MainActivity : AppCompatActivity(), View.OnClickListener {
    lateinit var jumpVideoButton: Button

    private val launcher =
        registerForActivityResult(ActivityResultContracts.StartActivityForResult()){ activityResult -> {
        }
        }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        PermissionUtils.requestMyPermissions(this)
        jumpVideoButton = findViewById(R.id.jump_video)
        jumpVideoButton.setOnClickListener(this)
    }

    override fun onClick(v: View?) {
        when (v?.id) {
            R.id.jump_video -> {
                val intent = Intent().setAction("video_player")
                launcher.launch(intent)
            }
        }
    }
}