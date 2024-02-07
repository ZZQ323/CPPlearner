@echo off
setlocal enabledelayedexpansion
for %%i in (0,1,5) do(
    set name='A'
    if exist (name+i).cpp do (
        echo '%name%''%%i'"已经存在"
    ) else (
        echo include<bits/stdc++.h> > A.cpp
    )
)