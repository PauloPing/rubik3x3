CC = gcc
CFLAGS = -Wall -g
BINDIR = ../bin/
RACIR = ../
OBJS = main.o

all : $(BINDIR)$(OBJS)

$(BINDIR)%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

main : $(BINDIR)$(OBJS)
	$(CC) $< -o $(RACIR)$@



clean :
	@ rm *.o *.test 2> /dev/null || true
	@ echo "cleaning done"