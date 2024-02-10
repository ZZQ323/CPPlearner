@echo off
set sleep=ping 127.0.0.1 -n
set /a n=1

:loop
echo 第%n%次循环开始...... %date% %time%
echo 开始干活....
echo 第%n%次循环结束...... %date% %time%
echo 休息五秒吧.....
%sleep% 5 > nul
set /a n+=1
goto loop  