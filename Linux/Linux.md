###一、Linux基础

####1.软件安装
1.源
2.相应操作
	1.`apt-get update`
	2.`apt-get upgrade *`
	3.`apt-cache search *`
####2.简单命令
`ls,cp,cat,touch,mkdir（创建新目录）,cd`
`家目录：1.cd $HOME 2.cd (缺省) 3.cd ～`
`上次工作目录：cd -`
`rm -f -r`

思考：100台机器互联
###二、Shell基础

####1.执行
1.bash 1.sh
 2.chmod a+x 1.sh
####2.语法
####if
```shell
if  [[ condition ]]; then
	#statements
fi
```
####for
```shell
for i in `seq 1 100`; do
	#statements
done
```
```shell
for (( i=0;i<10;i++ )); do
	#statements
done
```
####while
```shell
while [[ condition ]]; do
	#statements 
done
```
###三、Linux命令

####1.命令
`which`
`type`
`$PATH`
####2.文件类型
七种类型
####3.文件权限

####4.vim配置文件

.vimrc

### 四、系统信息

####1.终端

`whoami`

`/dev/tty`控制终端

`pty`虚拟终端

`/dev/pts/i` 实现虚拟终端

`ping`

练习：

1.实现wall命令发送广播

```shell
#!/bin/bash
for i in `w -h | awk '{print $2}'`; do
	echo "`who am i`" >> /dev/$i
	echo $1 >> /dev/$i
done
```

2.使用脚本输出本地局域网内部所有被占用的IP地址

```shell
#!/bin/bash
for i in `seq $1 $2`;do
	ping -c 2 -W 1 192.168.1.$i 2>&1 >/dev/null		#2>/dev/null 1>/dev/zero
	if [[ $? -eq 0 ]]; then
		echo "192.168.1.$i"
	fi
done
```

3.记录登录时间、退出时间、在线时长

#### 2.文件内容查阅

`cat`、`nl`、`head`、`tail`

练习：查看一个文件的第101-120行

`man ls | nl -b a -n ln -n rz -w 8 | head -n 120 |tail -n 20 >>log`

####特殊权限：

SUID:`chmod u+s`		执行程序时获取程序所有者权限

SGID:`chmod g+s`		用户在该目录里，有效组变为目录所属组

SBIT:`chmod o+t`		在该目录下，用户只能删除自己创建的内容

练习（重点）

userA userB 

TestGroup

/project

UserA、UserB互相读写，不能互相删除

