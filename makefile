FLAGS = -Wall -ansi -pedantic
OBJS = manipulate_string.o main.o convert_base.o
EXEC = convert

$(EXEC): $(OBJS)
	gcc $(FLAGS) -o $(EXEC) $(OBJS) -lm

$(EXEC).o: $(EXEC).c
	gcc $(FLAGS) -c $(EXEC).c

manipulate_string.o: manipulate_string.c
	gcc $(FLAGS) -c manipulate_string.c

convert_base.o: convert_base.c
	gcc $(FLAGS) -c convert_base.c

clean: 
	rm *.o $(EXEC)
