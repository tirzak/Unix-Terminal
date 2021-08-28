SRCS = $(shell find -name '*.[cS]')
OBJS = $(addsuffix .o, $(basename $(SRCS)))

CC = gcc
CFLAGS = -Wall -g -I include

terminal.out:
	$(CC) $(CFLAGS) $(SRCS) -o $@

terminal: terminal.out