@echo off

:next
echo 当前时间是：%time% 即 %time:~0,2%点%time:~3,2%分%time:~6,2%秒%time:~9,2%厘秒
call sleep.bat 3000
goto next
pause 