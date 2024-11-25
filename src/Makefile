HEADERS := ../include/$(wildcard *.h)
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c =.o)
CC := gcc-14
CARGS := -Wextra -Wall

all: infixPostfix

infixPostfix : $(OBJS) $(HEADERS)
	$(CC) $(CARGS) $(OBJS) -o infixPostfix

%.o : %.c
	$(CC) $(CARGS) -c $< -o $@

