//
// Created by boxun.zhao on 2023/12/28.
//

/*
 * 概念
 * 1.什么是Linux系统？
 * Linux文件系统一切皆是文件
 *
 * 2.什么是用户空间，内核空间，fd？
 * 内核空间和用户空间是两个相对独立的空间，内核空间是运行核心代码的 内存区域，而用户空间是运行应用程序的 内存区域。
 * 内核空间拥有访问硬件设备的所有权限，即被保护的内存区域
 *
 * fd File Descriptor 文件描述符 可以对文件操作 类似id
 *
 * 3.什么是进程？
 * 进程是程序的基本执行实体 在当代面向线程设计的计算机结构中，进程是线程的容器。
 * 从实现角度看，进程是一种数据结构 有PCB块 （Process Control Block 存放进程的管理和控制信息的数据结构称为 进程控制块）
 *
 * 4.父子进程相关问题
 * fpid=fork() 如果fpid为0 也就是子 fpid 有点像链表 子没有子 就是0  fork后的代码 父子都会执行
 * 孤儿进程 父亲死掉的子进程
 * 僵尸进程 当子进程比父进程先结束 而父进程又没有回收子进程（子进程残留的资源(PCB)存放在内核中）
 * 因为每个进程结束之后，都会释放自己地址空间中的用户区数据，内核区的PCB没有办法自己释放掉，需要父进程去释放。
 * 解决僵尸进程的方法？
 * 1.杀死父 这样不合理
 * 2.在父进程中调用wait()  waitpid()回收子进程残留的资源
 *
 * 5.进程间怎么通讯？
 * mmap 管道 文件 socket
 *
 */