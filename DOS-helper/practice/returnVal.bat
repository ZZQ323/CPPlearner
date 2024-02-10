@echo off

REM 设置返回值为 0
set "returnValue=0"

REM 执行一些操作...

REM 如果发生错误，设置返回值为 1
dir nonexist > nul
if errorlevel 1 (
    set "returnValue=1"
)

REM 在脚本结束时输出返回值
echo 返回值：%returnValue%

REM 结束脚本
exit /b %returnValue%