@echo off
set ifo=abcdefghijklmnopqrstuvwxyz0123456789
echo 原字符串（第二行为各字符的序号）:
echo %ifo%
echo 123456789012345678901234567890123456
echo 截取前5个字符:
echo %ifo:~0,5%
echo 截取最后5个字符:
echo %ifo:~-5%
echo 截取第一个到倒数第6个字符:
echo %ifo:~0,-5%
echo 从第4个字符开始,截取5个字符:
echo %ifo:~3,5%
echo 从倒数第14个字符开始,截取5个字符:
echo %ifo:~-14,5%
pause > nul