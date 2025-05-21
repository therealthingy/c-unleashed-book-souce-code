
# important: compile with optimizations off

.PHONY: all
all: bubble speed

speed: speed.c
	gcc -ansi -W -Wall -Wno-unused -lm -o speed speed.c

bubble.o: bubble.c
	gcc -pg -c -ansi -W -Wall -Wno-unused bubble.c

bubble: bubble.o
	gcc -pg bubble.o -o bubble

.PHONY: clean
clean:
	@$(RM) speed bubble *.o gmon.out

