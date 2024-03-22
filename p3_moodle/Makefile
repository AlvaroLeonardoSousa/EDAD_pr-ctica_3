CC=gcc
CFLAGS=-Wall -ggdb
IFLAGS=-I./
LDFLAGS=-L./
CLIB= -lqueue -L.
LIBS = -lm 

.PHONY: clean_objects clean_program clean all

all: p3_e1

##############################################

p3_e1.o: p3_e1.c queue.h maze.h
	$(CC) $(CFLAGS) -c $<

##############################################

p3_e1: p3_e1.o maze.o elements.o sorted_queue.o libqueue.a
	$(CC) -o $@ $^ $(CLIB) $(LIBS)

sorted_queue.o: sorted_queue.c sorted_queue.h elements.h queue.h types.h maze.h
	$(CC) $(CFLAGS) -c $< 

maze.o: maze.c maze.h types.h
	$(CC) $(CFLAGS) -c $<

elements.o: elements.c elements.h
	$(CC) $(CFLAGS) -c $<

#################################################

valgrind: 
	valgrind --leak-check=full 

#################################################

clean_objects:
	@echo "Cleaning objects..."
	@rm -f *.o

clean_program:
	@echo "Cleaning program..."
	@rm -f p2_e1 p2_e2 p2_e3 p2_e1s p2_e2s p2_e3s p2_e1extra 

clean: clean_objects clean_program