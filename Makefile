cc = g++

all:
	$(cc) TermRet.cpp -o termret.exe
	termret.exe
build:
	$(cc) TermRet.cpp -o termret.exe
run:
	termret.exe