Atmega32_ps2avr
--------------------------------------
1 直接6pin刷上去 hfuse D8或者D0 lfuse 0F 
千万不能用bface和faceU的bootloader！
2 刷完固件后，键盘灯正常，识别正常，但是就是不出字。
原因是pid和vid冲突，系统自带的HID驱动识别为vendor而不是keycode。
重启电脑即可正确识别为keycode。此现象很罕见。
3 hidraw上传有时候需要敲一下任意键唤醒才会启动。
---------------------------------------
hidraw发送格式 interface 2 endpoint 4
8byte 50ms 无需处理raw回复信息 
如果没有接收响应则会卡死 拔掉usb插头即可
FF F1 00 00 00 00 00 00
address address data1 data1 data2 data2 data3 data3
address address data1 data1 data2 data2 data3 data3
address address data1 data1 data2 data2 data3 data3
...
FF F2 00 00 00 00 00 00
---------------------------------------
eep格式
前10byte是5个16位数：
 row地址 col地址 矩阵1地址 矩阵2地址 矩阵mask地址
//   10    10+5=15   10+5+14=29   10+5+14+70=99  10+5+14+140=169
其它信息都是8位数：
row[5]
col[14]
hexakey0[5,14]
hexakey1[5,14]
keymask[5,14]
---------------------------------------