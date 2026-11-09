.PHONY: all

all: Grit.exe

Grit.exe: src/main.cpp
	g++ -o artifacts/windows/Grit.exe src/main.cpp -lraylib
