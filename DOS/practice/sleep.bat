@echo off

set /a n=1
:loop
if "%n%"=="%1" (
    goto out
)
set /a n+=1
goto loop
:out
