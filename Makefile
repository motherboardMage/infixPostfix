HEADERS := include/$(wildcard *.h)
SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:src/%.c = src/%.o)
CARGS := -Wextra -Wall

all: infixPostfix

infixPostfix : $(OBJS) $(HEADERS)
	gcc-14 $(CARGS) $(OBJS) -o infixPostfix

src/%.o : src/%.c
	gcc-14 $(CARGS) -c $< -o $@