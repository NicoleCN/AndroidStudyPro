//
// Created by boxun.zhao on 2023/12/28.
//

/*
 * http://androidxref.com/7.0.0_r1/xref/system/core/init/init.cpp
 * argc表示是命令行总的参数个数 比如 main aa bb argc=3 因为main也算一个
 *
 * init 分为三个阶段
 * 一阶段
 *       ueventd/watchdog后通过变量 is_first_stage
 *       挂载文件系统
 *       日志初始化
 *       初始化SELinux   安全策略（是一个linux安全增强功能，其允许用户和管理员对访问控制有更多的控制权。）
 *       重新执行 main 方法，进入第二阶段
 * 二阶段
 *       主要是一些属性property 处理cmd命令行属性  其余系统属性
 *       SELinux具体实现 给文件打标签创建上下文
 *
 * 三阶段
 */
 int main(int argc, char** argv) {
    //strcmp 函数 比较字符串相等的为 0
    //basename 函数 拿到第一个参数的命令路径
    //通过分析 http://androidxref.com/7.0.0_r1/xref/system/core/init/Android.mk 可知，
    //ueventd.c、watchdog.c与init.c被编译成了同一个可执行文件“/init”，并创建了软链接“/sbin/ueventd”、“/sbin/watchdog”指向“/init”:
    //http://androidxref.com/7.0.0_r1/xref/system/core/rootdir/init.rc 里面定义了 并且在on early-init的时候启动 ueventd
    if (!strcmp(basename(argv[0]), "ueventd")) {
        //事件分发进程
        //以sbin/ueventd"拉起init时，启动ueventd进程
        return ueventd_main(argc, argv);
    }

    if (!strcmp(basename(argv[0]), "watchdogd")) {
        //以"sbin/watchdogd"拉起init时，启动watchdogd进程
        return watchdogd_main(argc, argv);
    }

    if(is_first_stage){

    }else{

    }
    //在内核完成系统设 置后，它首 先在系统文件中寻找 init.rc 文件，并启动 init 进程。
    Parser解析init.rc文件
    //将这些配置转换成一个个数组、队列，然后开启无限循环去处理这些数组、队列中的 command 和 service，并且通过 epoll 监听子进程结束和属性设置
    //这些 service 通常不是普通的服务，文档里面的称呼是daemon（守护进程）所谓守护进程就是这些服务进程会在系统初始化时启动，并一直运行于后台，直到系统关闭时终止。
    //启动servicemanager 和 zygote 等服务(进程)，最后 init 进程进入了 loop
    //守护进程 是运行在后台的一种特殊进程
 }