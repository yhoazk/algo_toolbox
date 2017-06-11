
prog_name = fibo

CC = g++ -g -std=c++11 -O2 -pipe
#CC = gcc -g



all: clean comp run

clean:
	rm -rf ./${prog_name}.exe

comp:
	${CC} -o ${prog_name}.exe ${prog_name}.cpp

run:
	./${prog_name}.exe


debug:
	gdb ./${prog_name}.exe
