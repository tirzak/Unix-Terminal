SRCS = $(shell find -name '*.[cS]')
OBJS = $(addsuffix .o, $(basename $(SRCS)))

CC = gcc
CFLAGS = -Wall -g -I include

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<