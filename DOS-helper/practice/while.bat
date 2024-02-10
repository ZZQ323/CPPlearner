@echo off

set i=1
:loop
echo "i:"%i%
if %i% EQU 6 (
    goto :out
)
set /a i+=1
goto :loop

:out