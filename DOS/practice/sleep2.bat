@echo off
set sleep=ping 127.0.0.1 -n
set /a n=1

:loop
echo ��%n%��ѭ����ʼ...... %date% %time%
echo ��ʼ�ɻ�....
echo ��%n%��ѭ������...... %date% %time%
echo ��Ϣ�����.....
%sleep% 5 > nul
set /a n+=1
goto loop  