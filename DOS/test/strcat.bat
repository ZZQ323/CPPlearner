@echo off
set str1=This is string1
set str2=This is string2
::设置str1和str2中存储的字符串
echo 连接字符串以前：
echo str1=%str1%
echo str2=%str2%
::先输出一次原有的字符串
set str1=%str1% %str2%
::字符串连接
echo 连接字符串以后：
echo str1=%str1%
echo str2=%str2%
::输出执行完字符串连接后的两个字符串
echo 输出完毕，按任意键退出 && pause > nul
