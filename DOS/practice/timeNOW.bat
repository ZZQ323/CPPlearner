@echo off

:next
echo ��ǰʱ���ǣ�%time% �� %time:~0,2%��%time:~3,2%��%time:~6,2%��%time:~9,2%����
call sleep.bat 3000
goto next
pause 