CC = gcc
CFLAGS = -Wall -g
SRCDIR = src/
BINDIR = bin/
MODELEDIR = src/modele/
VUEDIR = src/vue/
OBJS =  main.o methode.o

all : $(OBJS)

%.o : $(MODELEDIR)%.c
	$(CC) $(CFLAGS) -c $<
	mv $@ $(BINDIR)



clean :
	@ rm $(BINDIR)*.o main 2> /dev/null || true
	@ echo "cleaning done"