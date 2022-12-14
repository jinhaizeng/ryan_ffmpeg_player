# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# Declares and names the project.

project("ryan_ffmpeg_player")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        ryan_ffmpeg_player

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ryan_ffmepg_player.c)

# 获取目录上一级的做法
# https://cloud.tencent.com/developer/ask/sof/46411
# 参数1：接收参数名称
# 参数2：需要操作的路径，在路径后面加 /.. ，类似 linux 的 .. ,就是返回上级
# 参数3: ABSOLUTE 表示绝对路径
#get_filename_component(VAR_PARENT ${CMAKE_CURRENT_SOURCE_DIR}/.. ABSOLUTE)

# 声明变量 third_part_jni_path、third_part_header_path
# ../jni 表示当前路径的上一级路径，之后上一级路径查找子目录 jni
#set(third_part_jni_path ../jni)
get_filename_component(third_part_jni_path ${CMAKE_CURRENT_SOURCE_DIR}/../jni ABSOLUTE)
MESSAGE("third_part_jni_path = ${third_part_jni_path}")
# 头部文件所在的目录
set(third_part_header_path ${third_part_jni_path}/include)
# so 库所存在的文件夹
set(third_part_lib_path  ${third_part_jni_path}/arm64-v8a)
MESSAGE("shenlong ${third_part_lib_path}")

# ${CMAKE_ANDROID_ARCH_ABI} 是获取 Cpu 架构的
MESSAGE("HI ${CMAKE_ANDROID_ARCH_ABI}")
# 设置扫描 so 库对应的请求头目录
INCLUDE_DIRECTORIES(${third_part_header_path})

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# 导入 ffmpeg 相关的动态库
# 1、导入 avcodec
# add_library
# 参数1：库的名称
# 参数2：表示共享库
# 参数3：表示导入
add_library(avcodec SHARED IMPORTED)
# set_target_properties
# 参数1：库的名称
# 参数2：表示设置路径的属性，就是导入本地路径
# 参数3：本地路径
set_target_properties(avcodec
        PROPERTIES IMPORTED_LOCATION
        ${third_part_lib_path}/libavcodec.so)

# 2、导入 avdevice
add_library(avdevice
        SHARED
        IMPORTED)
set_target_properties(avdevice
        PROPERTIES IMPORTED_LOCATION
        ${third_part_lib_path}/libavdevice.so)

# 3、导入 avfilter
add_library(avfilter
        SHARED
        IMPORTED)
set_target_properties(avfilter
        PROPERTIES IMPORTED_LOCATION
        ${third_part_lib_path}/libavfilter.so)
# 4、导入 avformat
add_library(avformat
        SHARED
        IMPORTED)
set_target_properties(avformat
        PROPERTIES IMPORTED_LOCATION
        ${third_part_lib_path}/libavformat.so)
# 5、导入 avutil
add_library(avutil
        SHARED
        IMPORTED)
set_target_properties(avutil
        PROPERTIES IMPORTED_LOCATION
        ${third_part_lib_path}/libavutil.so)
# 6、导入 postproc
add_library(postproc
        SHARED
        IMPORTED)
set_target_properties(postproc
        PROPERTIES IMPORTED_LOCATION
        ${third_part_lib_path}/libpostproc.so)
# 7、导入 swresample
add_library(swresample
        SHARED
        IMPORTED)
set_target_properties(swresample
        PROPERTIES IMPORTED_LOCATION
        ${third_part_lib_path}/libswresample.so)
# 8、导入 swscale
add_library(swscale
        SHARED
        IMPORTED)
set_target_properties(swscale
        PROPERTIES IMPORTED_LOCATION
        ${third_part_lib_path}/libswscale.so)

# 将我们自己编写的库与第三方库进行关联
target_link_libraries(
        ryan_ffmpeg_player
        avcodec
        avdevice
        avfilter
        avformat
        avutil
        postproc
        swresample
        swscale

        ${log-lib}
)