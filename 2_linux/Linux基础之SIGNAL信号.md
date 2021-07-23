## 信号
信号(signal)是一种软中断，信号机制是进程间异步通信通信的一种方式。


## 信号表
信号定义在 **signal.h** 头文件中，使用`kill -l`查看信号表
 值 | 名称    | 解释                     | 说明                         | aa  | 默认动作 
--- | ---    | ---                      | ---                          | --- | ---
 1  | HUP    | Hangup                   | 挂起(终端挂起或控制进程终止)   | 33  | 终止进程
 2  | INT    | Interrupt                | 中断(键盘组合键ctrl + c)      | 34  | 终止进程
 3  | QUIT   | Quit                     | 退出                         | 35  | 退出程序
 4  | ILL    | Illegal instruction      | 非法指令                     | 36  |
 5  | TRAP   | Trap                     | 断点或trace trap，跟踪代码执行 | 37  |
 6  | ABRT   | Aborted                  | abort发出的信号               | 38  |
 7  | BUS    | Bus error                | [非法内存访问](#非法内存与无效内存) | 39  |
 8  | FPE    | Floating point exception | 浮点异常(运算错误，溢出，除零等)| 40  | 终止进程并产生core文件
 9  | KILL   | Killed                   | kill信号(不进行清理和暂存工作)| 41  | 无条件终止进程
10  | USR1   | User signal 1            | 用户信号1                    | 42  |  
11  | SEGV   | Segmentation fault       | [无效内存访问](#非法内存与无效内存) | 43  |  
12  | USR2   | User signal 2            | 用户信号2                    | 44  | 
13  | PIPE   | Broken pipe              | 管道破损，没有读端的管道写数据 | 45  |
14  | ALRM   | Alarm clock              | alarm发出的信号，定时器超时   | 46  | 终止进程
15  | TERM   | Terminated               | 终止信号(可以被阻塞和终止)    | 47  |  
16  | STKFLT | Stack fault              | 栈溢出                       | 48  |
17  | CHLD   | Child exited             | 子进程退出                   | 49  | 默认忽略
18  | CONT   | Continue                 | 进程继续                     | 50  |
19  | STOP   | Stopped (signal)         | 进程停止                     | 51  |
20  | TSTP   | Stopped                  | 进程停止                     | 52  | 
21  | TTIN   | Stopped (tty input)      | 进程停止，后台进程从终端读数据 | 53  | 
22  | TTOU   | Stopped (tty output)     | 进程停止，后台进程向终端写数据 | 54  |
23  | URG    | Urgent I/O condition     | I/O紧急数据到达当前线程       | 55  | 默认忽略
24  | XCPU   | CPU time limit exceeded  | 进程CPU时间片到期             | 56  |
25  | XFSZ   | File size limit exceeded | 文件大小超出上限              | 57  |
26  | VTALRM | Virtual timer expired    | 虚拟时钟超时                  | 58  |
27  | PROF   | Profiling timer expired  | profile时钟超时              | 59  |
28  | WINCH  | Window size changed      | 窗口大小改变                 | 60  | 默认忽略
29  | IO     | I/O possible             | I/O相关                     | 61  |
30  | PWR    | Power failure            | 关机                        | 62  | 默认忽略
31  | SYS    | Bad system call          | 系统调用异常                 | 63  |
32  | 32     | Signal 32                |                             | 64  |

## 非法内存与无效内存
非法内存
无效内存：进程试图去访问其虚地址空间以外的位置

## 捕获信号
### trap
trap命令常用于捕获信号`trap commands signals`

信号捕获后的常用操作：
1. 清理临时文件：`trap "rm -f $WORKDIR/work1$$ $WORKDIR/dataout$$; exit" 1 2`  
    注意点：单引号和双引号的意义不同，双引号执行到 trap 命令时就会替换 WORKDIR 和 $$ 的值。如果希望接收到 SIGHUP 或 SIGINT 信号时再替换其值，那么可以将命令放在单引号内
2. 忽略信号：`trap '' 1 2 3 15`
    注意点：单引号不可省略
3. 恢复默认动作：`trap 1 2 3`

### signal
不支持信号传递信息，主要用于非实时信号安装

### signaction
支持信号传递信息，可用于所有信号安装

## 发送信号
kill(), raise(), sigqueue(), alarm(), setitimer(), abort()
### kill

### sigqueue



https://www.jianshu.com/p/f445bfeea40a
http://gityuan.com/2015/12/20/signal/