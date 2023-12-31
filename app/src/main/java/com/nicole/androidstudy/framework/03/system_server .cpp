//
// Created by boxun.zhao on 2023/12/29.
//

/*
* SystemServer进程
* 由Zygote fork而来 Java调用nativeForkSystemServer
* 创建出新进程之后
* 创建一些类加载器 启动应用进程 后 ZygoteInit.zygoteInit Java方法
*/

//http://androidxref.com/7.0.0_r1/xref/frameworks/base/core/java/com/android/internal/os/ZygoteInit.java
public static final void zygoteInit(int targetSdkVersion, String[] argv,
            ClassLoader classLoader) throws Zygote.MethodAndArgsCaller {

  RuntimeInit.redirectLogStreams(); // 重定向 log 输出
  RuntimeInit.commonInit(); // 通用的一些初始化 捕获异常 TIME.zone

  //这里注意 底层其实 调用 ProcessState::self() 其是单例模式  主要工作是调用 open() 打开 /dev/binder 驱动设备
  //再利用 mmap() 映射内核的地址空间 将Binder 驱动的 fd 赋值 ProcessState 对象中的变量 mDriverFD，
  //底层proc->startThreadPool(); // 启动新 binder 线程   不断和驱动talk
  ZygoteInit.nativeZygoteInit(); // zygote 初始化

  // 应用初始化
  // 其作用 调用最终 反射调用SystemServer 类的 main() 方法
  //实际 SystemServer().run() 方法
  //run方法做了什么操作？
  //时间 语言环境
  //调用 createSystemContext() 创建 System_service进程的上下文context
  //创建SystemServiceManager
  //开启很多服务
  //startBootstrapServices()、 引导服务
  //其中有ActivityManagerService、
  //PowerManagerService、LightsService、DisplayManagerService、
  //PackageManagerService、UserManagerService、SensorService 这些服务。

  //startCoreServices()、 核心服务
  //有DropBoxManagerService、BatteryService、UsageStatsService、WebViewUpdateService 这些服务

  //startOtherServices()，创建和运行系统中所有的服务
  //loop 循环
  RuntimeInit.applicationInit(targetSdkVersion, argv, classLoader);
}

