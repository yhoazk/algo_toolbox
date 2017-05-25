
prog_name = assing_1

CC = g++ -pipe -g -std=c++11
#CC = gcc -g



all: clean comp run

clean:
	rm -rf ./${prog_name}.exe

comp:
	${CC} -o ${prog_name}.exe ${prog_name}.cpp

run:
	./${prog_name}.exe < input


debug:
	gdb ./${prog_name}.exe
