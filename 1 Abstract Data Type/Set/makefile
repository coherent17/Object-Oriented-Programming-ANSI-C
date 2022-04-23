CC = gcc
CFLAGS = -g -Wall -O3
OBJS = Set.o
BINS = main

all: $(BINS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BINS): main.c $(OBJS)
	$(CC) $(CFLAGS)  $^ -o $@

do:
	./$(BINS)


clean:
	rm $(BINS) $(OBJS)