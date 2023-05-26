demo: main.o define.o
	gcc ./build/target/main.o ./build/target/define.o -o ./build/demo

define.o: ./src/stumgt/define.c
	gcc ./src/stumgt/define.c -c -o ./build/target/define.o

main.o: ./src/main.c
	gcc ./src/main.c -c -o ./build/target/main.o