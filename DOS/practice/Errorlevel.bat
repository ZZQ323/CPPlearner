echo off

REM ģ��һ�����ش��󼶱�Ϊ 2 ������
dir nonexistent_folder

REM �����󼶱��Ƿ���ڵ��� 1
if errorlevel 1 (
    echo �����������󼶱���ڵ��� 1
) else (
    echo û�д��󣬴��󼶱�С�� 1
)

:: ��ʱ��Ӧ����c
@REM set c=dfasfdsafadaf
@REM if errorlevel %c% (
@REM    echo c�ܱȽ��ַ���
@REM ) else (
@REM    echo c���ܱȽ��ַ���
@REM )