CC=gcc
CFLAGS=-Wall -ggdb
IFLAGS=-I./
LDFLAGS=-L./
CLIB= -lqueue -L.
CLIBS= -lstack
LIBS = -lm 

.PHONY: clean_objects clean_program clean all

all: p3_e1 p3_e2

allq: p3_e1s p3_e2s

##############################################

p3_e1.o: p3_e1.c queue.h maze.h
	$(CC) $(CFLAGS) -c $<

p3_e2.o: p3_e2.c queue.h maze.h
	$(CC) $(CFLAGS) -c $<


##############################################

p3_e1: p3_e1.o maze.o elements.o sorted_queue.o libqueue2.a
	$(CC) -o $@ $^ $(CLIB) $(LIBS)

p3_e2: p3_e2.o search.o maze.o libqueue2.a libstack.a
	$(CC) -o $@ $^ $(CLIB) $(CLIBS)  $(LIBS) 

##################################################

p3_e1s: p3_e1.o maze.o elements.o sorted_queue.o libqueue2.a
	$(CC) -o $@ $^ $(CLIB) $(LIBS)

p3_e2s: p3_e2.o search.o maze.o libqueue2.a libstack.a
	$(CC) -o $@ $^ $(CLIB) $(CLIBS)  $(LIBS) 

##################################################


sorted_queue.o: sorted_queue.c sorted_queue.h elements.h queue.h types.h maze.h
	$(CC) $(CFLAGS) -c $< 

list.o: list.c list.h types.h
	$(CC) $(CFLAGS) -c $<

queue.o: queue.c queue.h list.h types.h
	$(CC) $(CFLAGS) -c $<

maze.o: maze.c maze.h types.h
	$(CC) $(CFLAGS) -c $<

elements.o: elements.c elements.h
	$(CC) $(CFLAGS) -c $<

search.o: search.c types.h maze.h
	$(CC) $(CFLAGS) -c $<

#################################################

libqueue2.a: queue.o list.o
	ar rcs $@ $^

#################################################

valgrind: 
	valgrind --leak-check=full 

#################################################

clean_objects:
	@echo "Cleaning objects..."
	@rm -f *.o

clean_program:
	@echo "Cleaning program..."
	@rm -f p3_e1 p3_e2 p3_e1s p3_e2s 

clean: clean_objects clean_program