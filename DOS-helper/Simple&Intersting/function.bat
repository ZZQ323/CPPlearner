@echo off

rem 主程序
echo 主程序开始
call :myFunction 123 "Hello, world!"
echo 主程序结束
pause
exit /b 0

rem 子程序
:myFunction
echo 子程序开始
echo 参数1：%1
echo 参数2：%2
echo 子程序结束
exit /b 0