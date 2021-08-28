SRCS = $(shell find -name '*.[cS]')
OBJS = $(addsuffix .o, $(basename $(SRCS)))

CC = gcc
CFLAGS = -Wall -g -I include

program:
	$(CC) $(CFLAGS) $(SRCS) -o $@