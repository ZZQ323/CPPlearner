@echo off

REM ���÷���ֵΪ 0
set "returnValue=0"

REM ִ��һЩ����...

REM ��������������÷���ֵΪ 1
dir nonexist > nul
if errorlevel 1 (
    set "returnValue=1"
)

REM �ڽű�����ʱ�������ֵ
echo ����ֵ��%returnValue%

REM �����ű�
exit /b %returnValue%