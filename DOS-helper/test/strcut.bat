@echo off
set ifo=abcdefghijklmnopqrstuvwxyz0123456789
echo ԭ�ַ������ڶ���Ϊ���ַ�����ţ�:
echo %ifo%
echo 123456789012345678901234567890123456
echo ��ȡǰ5���ַ�:
echo %ifo:~0,5%
echo ��ȡ���5���ַ�:
echo %ifo:~-5%
echo ��ȡ��һ����������6���ַ�:
echo %ifo:~0,-5%
echo �ӵ�4���ַ���ʼ,��ȡ5���ַ�:
echo %ifo:~3,5%
echo �ӵ�����14���ַ���ʼ,��ȡ5���ַ�:
echo %ifo:~-14,5%
pause > nul