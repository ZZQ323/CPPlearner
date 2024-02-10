@echo off
set aa=C:\Windows\PPP\a.btx
call :deal aaa %aa% "c c" ddd eee
pause 
goto :eof

::如果不这么写，这个代码块又会被多执行一次
:deal
echo %%0 = %0
echo %%1 = %1
echo %%2 = %2
echo %%3 = %3
echo %%4 = %4
echo %%5 = %5

goto :eof