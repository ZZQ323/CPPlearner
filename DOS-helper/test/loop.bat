@echo off
::for %%i in (*) do (echo %%i)
::for %%i in (C:\*url) do (echo %%i)
::for /r %%i in (*.exe) do (echo %%i)

@REM (l,step,r）
for /l %%i in (1,1,5) do (echo %%i)

::参数可结合使用，/d表示遍历文件夹，/r表示深度遍历，/l 表示序列
::不允许在for命令中类似上步中声明变量并直接使用 for ... do(setx X=100)

::for命令中临时变量的使用：
::需启用变量延迟功能，命令：setlocal enabledelayedexpansion
::for命令中的I临时rem注释内容：表示截取从下标0开始的之后4个字符，输出dasu

::echo %name:~0,4%变量使用时用！key！感汉号括起来的形式代替%key%

::https://blog.51cto.com/runcx/2465152
