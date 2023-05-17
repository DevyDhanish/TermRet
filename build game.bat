@echo off

set /p inputFile=Enter the filename you want to build :
set /p outputFile=Name of output file :

g++ /games/"%inputFile%.cpp" -o /build/"%outputFile%.exe"