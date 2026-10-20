CC = gcc
CFLAGS = -Wall -g

list: main.c list.c list.h
	  $(CC) $(CFLAGS) -o list main.c list.c

clean:
	  rm -f list list.exe