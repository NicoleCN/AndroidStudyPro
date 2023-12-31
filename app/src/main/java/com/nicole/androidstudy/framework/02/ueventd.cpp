//
// Created by boxun.zhao on 2023/12/28.
//

/*
* 主要解析ueventd.rc文件 管理设备节点权限
* 初始化设备信息
* 循环polling uevent消息 poll机制 不是epoll
* epoll与poll相比具有更高的效率，能够大幅减少轮询带来的开销
*/

int ueventd_main(int argc, char **argv) {

}