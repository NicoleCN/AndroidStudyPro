
/**
 * 看门狗
 * 用于系统出问题时重启系统
 * 原理
 * //打开"/dev/watchdog fd
 * //设置看门狗超时时间 second
 * 每10s 喂狗一次 计时器清0 重新计时
 */
int watchdogd_main(int argc, char **argv) {

}
