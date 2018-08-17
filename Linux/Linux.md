##Linux基础
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
##Shell
####1.执行
1.bash 1.sh
 2.chmod a+x 1.sh
####2.语法
####if
```
if  [[ condition ]]; then
	#statements
fi
```
####for
```
for i in `seq 1 100`; do
	#statements
done
```
```
for (( i=0;i<10;i++ )); do
	#statements
done
```
####while
```
while [[ condition ]]; do
	#statements 
done
```
##Linux
####命令
`which`
`type`
`$PATH`
####文件类型
七种类型
####文件权限
##双系统
1.划分空间（磁盘管理-压缩原来卷-压缩100G-新建卷（NTFS））
2.BIOS 
3.启动方式
	1.BIOS
	2.UEFI
	3.关闭安全启动（secure boot）
4.插入U盘（软碟通制作安装盘）
5.选择从U盘启动（F12，选择合适的启动项）
6.不需要连接wifi
7.为无线网卡和设备安装驱动，选定
8.划分磁盘
	1.确定之前准备好的空间（总大小，已用）
	2.（1）UEFI：500M  efi系统分区
	   （2）500 ext4   /boot
	   （3）swap：交换空间  大小为内存的两倍
	   （4）/:  ext4
	   (5)	确定引导安装位置：boot形式	
	
![](/home/yuxiaowei/Desktop/lALPBbCc1rI4MhvNA0jNBvo_1786_840.png) 

1.`yuxiaowei@yuxiaowei:/etc$ ls *.conf>>/home/yuxiaowei/a`

####vim配置文件
.vimrc