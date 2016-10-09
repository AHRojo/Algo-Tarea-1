OBJS= main.o
%.o: %.c
	gcc -c $^ -Wall
programa: $(OBJS)
	gcc $^ -o programa -Wall
clean:
	find . -name '*.o' -type f -delete
	rm -f programa
