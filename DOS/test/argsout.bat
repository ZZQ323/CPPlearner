@echo off

setlocal ENABLEDELAYEDEXPANSION

REM ��ȡ���в���

set allArgs=%*
echo "allArgs:"%allArgs%
set "allArgs=%*"
echo "allArgs:"%allArgs%

REM �����һ��������ʼ�������һ���ո��λ��
for /L %%i in (0,1,999) do (
    set "currentArg=!allArgs:* =!"
    ::ȥ��һ���ո�ǰ�������ַ���
    if not "!currentArg!"=="!allArgs!" (
        set "lastArg=!currentArg!"
        set "allArgs=!allArgs:~1!"
    ) else (
        goto :done
    )
)

:done
echo ���һ��������: %lastArg%
