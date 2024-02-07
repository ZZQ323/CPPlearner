@echo off

set a=10
set b=5

if %a% gtr %b% (
   echo a is greater than to b
)else (
   echo a is less or equal than b
)

if %a% equ %b% (
   echo a is equal to b
)else (
   echo a is not equ b
)
