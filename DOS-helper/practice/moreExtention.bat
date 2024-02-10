@echo off
set "filePath=\myfile.txt"
for %%I in ("%filePath%") do set "filePath=%%~fI"
echo %filePath%