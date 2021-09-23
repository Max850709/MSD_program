
SRCDIR=final_pushbox

INCLUDE=-I/opt/homebrew/include/

# Compilation Flags
CFLAGS=-std=c++11 $(INCLUDE)
# Linking Flags
LFLAGS=-L/opt/homebrew/lib -lsfml-graphics -lsfml-system -lsfml-window

CC=g++

.PHONY : all
all : game

OBJS=main.o

Ball.o : $(SRCDIR)/Ball.cpp
    $(CC) $(CFLAGS) -c $<

main.o : $(SRCDIR)/main.cpp
    $(CC) $(CFLAGS) -c $<

game : $(OBJS)
    $(CC) $(LFLAGS) -o game $(OBJS)

