
prog_name = max_pairwise_product

CC = g++ -g -std=c++11
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
