# Variable pour compiler
CC = gcc
CFLAGS = -Wall -g

# Chemin
SRCDIR = src/
BINDIR = bin/
MODELEDIR = src/modele/
VUEDIR = src/vue/

# Fichier .o
OBJS = $(BINDIR)main.o $(BINDIR)methode.o 
OBJSVUE = $(BINDIR)mainVue.o

all : $(OBJS) $(OBJSVUE) main

$(BINDIR)%.o : $(MODELEDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BINDIR)%.o : $(VUEDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

main : $(BINDIR)main.o
	$(CC) $< -o $@
	./$@

clean :
	@ rm $(BINDIR)*.o main 2> /dev/null || true
	@ echo "cleaning done"