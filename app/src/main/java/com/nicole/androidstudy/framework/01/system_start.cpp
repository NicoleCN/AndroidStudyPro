//
// Created by boxun.zhao on 2023/12/28.
//

/*
 *安卓如何启动?
 * 按下开机键一瞬间，内存中什么也没有
 * 借助 Bootloader 初始化硬件 建立内存空间映像图 总之就是环境
 *
 * 什么是ROM？
 * 安卓没有硬盘，而是ROM划分区域
 *
 * 回头再回答第一个问题
 * bl找到ROM里面的操作系统并加载相关文件到RAM内存中
 * 此后会进行Linux环境初始化 硬件 驱动 挂载根文件系统等
 * Linux 内核加载的最后阶段会启动最后启动用户空间第一个进程init进程
 *
 * Linux内核东西多这里说下几个重点
 * Linux内核启动主要涉及3个进程
 * pid=0 Swapper(idle) init和kthreadd的父  唯一一个没有fork出来的 第一个进程
 * pid=1 init 第一个用户进程 是idle fork出来的
 * pid=2 kthreadd  线程之父 idle通过 kernel_thread 创建，并始终运行在内核空间  ,
 *
 */