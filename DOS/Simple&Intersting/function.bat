@echo off

rem ������
echo ������ʼ
call :myFunction 123 "Hello, world!"
echo ���������
pause
exit /b 0

rem �ӳ���
:myFunction
echo �ӳ���ʼ
echo ����1��%1
echo ����2��%2
echo �ӳ������
exit /b 0