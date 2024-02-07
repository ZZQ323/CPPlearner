echo off

REM 模拟一个返回错误级别为 2 的命令
dir nonexistent_folder

REM 检查错误级别是否大于等于 1
if errorlevel 1 (
    echo 错误发生，错误级别大于等于 1
) else (
    echo 没有错误，错误级别小于 1
)

:: 此时不应该有c
@REM set c=dfasfdsafadaf
@REM if errorlevel %c% (
@REM    echo c能比较字符串
@REM ) else (
@REM    echo c不能比较字符串
@REM )