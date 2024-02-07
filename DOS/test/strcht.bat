@echo off
Setlocal ENABLEDELAYEDEXPANSION
::启用命令扩展，参加setlocal /?命令
set str1=This is a test string
set ch1=t
::注意，这里是区分大小写的！
set str=%str1%
::复制字符串，用来截短，而不影响源字符串

:next
if not "%str%"=="" (
    set /a num+=1
    ::比较首字符是否为要求的字符，如果是则跳出循环
    if "!str:~0,1!"=="%ch1%" (
        goto last
    )
    set "str=%str:~1%"
    ::从第二个字符开始往后截取字符串
    goto next
)

set /a num=0
::没有找到字符时，将num置零

:last
echo 字符'%ch1%'在字符串"%str1%"中的首次出现位置为%num%
echo 输出完毕，按任意键退出 && pause>nul || exit


:: '' "" + % % 会展开
:: 变量赋值的时候 "set a=%xx%"