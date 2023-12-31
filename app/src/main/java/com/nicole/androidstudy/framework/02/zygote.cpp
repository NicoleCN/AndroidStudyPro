//
// Created by boxun.zhao on 2023/12/28.
//

/*
 *
 * 何为zygote？
 * zygote 进程就是 daemon 其中之一
 * 主要负责创建Java虚拟机 加载系统资源 启动SystemServer进程 以及在后续运行过程中启动普通的应用程序。
 *
 * init.rc中会start zygote有64还是32位
 * zygote的原文件是app_main.cpp
 * 最终会调用app_main.cpp的main
 * 其中会
 *
 * 两种模式
 * 一种是 zygote 模式 传递的参数有 --start-system-server --socket-name=zygote，前者表示启动 SystemServer，后者指定 socket 的名称。
 * 一种是 application 模式 也就是启动普通应用程序
 * 两种模式都是调用了AppRuntime 对象的 start 函数 加载 ZygoteInit 或 RuntimeInit 两个 Java 类
 * 遗留一个RuntimeInit没处理
 */
 main(){
    //http://androidxref.com/7.0.0_r1/xref/frameworks/base/cmds/app_process/app_main.cpp
    if (zygote) { // 如果是 zygote 启动模式，则加载 ZygoteInit
        //http://androidxref.com/7.0.0_r1/xref/frameworks/base/core/java/com/android/internal/os/ZygoteInit.java
        runtime.start("com.android.internal.os.ZygoteInit", args, zygote);
      } else if (className) {
        // 如果是 application 启动模式，则加载 RuntimeInit
        //http://androidxref.com/7.0.0_r1/xref/frameworks/base/core/java/com/android/internal/os/RuntimeInit.java
        runtime.start("com.android.internal.os.RuntimeInit", args, zygote);
    }
    //http://androidxref.com/7.0.0_r1/xref/frameworks/base/core/jni/AndroidRuntime.cpp
    //runtime.start 其实就是创建启动虚拟机
    //创建完成Java虚拟机后  注册JNI函数 JNI调用ZygoteInit（JAVA类） 的 main 函数

    //ZygoteInit.Java里面
    //preload()一些资源 preload 常用的 Java 类库、系统 resources，执行 gc() 清理内存，为 fork 子进程做好准备
    //startSystemServer() fork新进程
    //runSelectLoop() 进入epoll轮询机制

    //RuntimeInit.java 里面好像init了timezone
    //Thread.setDefaultUncaughtExceptionHandler(new UncaughtHandler());
    //好像没啥
 }