@echo off
Setlocal ENABLEDELAYEDEXPANSION
::����������չ���μ�setlocal /?����
set str1=This is a test string
set ch1=t
::ע�⣬���������ִ�Сд�ģ�
set str=%str1%
::�����ַ����������ض̣�����Ӱ��Դ�ַ���

:next
if not "%str%"=="" (
    set /a num+=1
    ::�Ƚ����ַ��Ƿ�ΪҪ����ַ��������������ѭ��
    if "!str:~0,1!"=="%ch1%" (
        goto last
    )
    set "str=%str:~1%"
    ::�ӵڶ����ַ���ʼ�����ȡ�ַ���
    goto next
)

set /a num=0
::û���ҵ��ַ�ʱ����num����

:last
echo �ַ�'%ch1%'���ַ���"%str1%"�е��״γ���λ��Ϊ%num%
echo �����ϣ���������˳� && pause>nul || exit


:: '' "" + % % ��չ��
:: ������ֵ��ʱ�� "set a=%xx%"