@echo off
set str1=This is string1
set str2=This is string2
::����str1��str2�д洢���ַ���
echo �����ַ�����ǰ��
echo str1=%str1%
echo str2=%str2%
::�����һ��ԭ�е��ַ���
set str1=%str1% %str2%
::�ַ�������
echo �����ַ����Ժ�
echo str1=%str1%
echo str2=%str2%
::���ִ�����ַ������Ӻ�������ַ���
echo �����ϣ���������˳� && pause > nul
