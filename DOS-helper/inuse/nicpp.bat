@echo off
:: %* 被变量固定的时候就是一个序列，变成序列+空格的一整个字符串
:: for里面就是一个序列

for %%i in (%*) do (
    echo  > %%i.cpp 
)
