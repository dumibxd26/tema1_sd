
FLAGS = -Wall -Wextra -std=c99
MACHINE_CODE = -c 

build: tema1

tema1: *.o
	gcc $(FLAGS) $^ -o $@
	
%.o: %.c
	gcc $(FLAGS) $(MACHINE_CODE) $^
	
clean:
	rm -rf *.o tema1

.PHONY: clean
	
