@echo off
@echo Test %2
@echo Test %2 >> result.txt
copy %2 maze.in > nul
ConsoleApplication1.exe
timer %1 2500 65536 >> result.txt
check %2 %2.a maze.out >> result.txt
if exist maze.in del maze.in
if exist maze.out del maze.out