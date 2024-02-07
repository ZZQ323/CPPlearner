@echo off

setlocal ENABLEDELAYEDEXPANSION

REM 获取所有参数

set allArgs=%*
echo "allArgs:"%allArgs%
set "allArgs=%*"
echo "allArgs:"%allArgs%

REM 从最后一个参数开始查找最后一个空格的位置
for /L %%i in (0,1,999) do (
    set "currentArg=!allArgs:* =!"
    ::去掉一个空格前的所有字符串
    if not "!currentArg!"=="!allArgs!" (
        set "lastArg=!currentArg!"
        set "allArgs=!allArgs:~1!"
    ) else (
        goto :done
    )
)

:done
echo 最后一个参数是: %lastArg%
