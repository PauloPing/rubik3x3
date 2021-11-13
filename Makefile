CC = gcc
CFLAGS = -Wall -g
BINDIR = bin/
# SRCDIR = src/
MODELEDIR = src/modele/
VUEDIR = src/vue/
OBJS = main.o
MAINFILE = main

all : $(BINDIR)$(OBJS) $(MAINFILE) go

$(BINDIR)%.o : $(MODELEDIR)%.c $(VUEDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

main : $(BINDIR)$(OBJS)
	$(CC) $< -o $@

go : 
	./$(MAINFILE)



clean :
	@ rm $(BINDIR)*.o main 2> /dev/null || true
	@ echo "cleaning done"