if exist *.php (
    del * /q
) else (
    echo "此目录下不存在PHP文件"
    @REM exit
)
