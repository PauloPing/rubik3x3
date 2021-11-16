# Variable pour compiler
CC = gcc
CCFLAGS = -Wall -g

# Chemin
SRCDIR = src/
BINDIR = bin/
MODELEDIR = src/modele/
VUEDIR = src/vue/

## PROGRAMME : 

# Fichier .o
OBJS = $(BINDIR)main.o $(BINDIR)methode.o 
OBJSVUE = $(BINDIR)mainVue.o

all : $(OBJS) executer # $(OBJSVUE) mainVue

$(BINDIR)%.o : $(MODELEDIR)%.c
	$(CC) $(CCFLAGS) -c $< -o $@

executer : 
	$(CC) $(CCFLAGS) $(BINDIR)main.o -o main
	./main


clean :
	@ rm $(BINDIR)*.o main mainVue 2> /dev/null || true
	@ echo "cleaning done"






# # Flags d'erreurs:
# ERROR_CFLAGS = -Wall -pedantic
# # Flags pour le compilateur:
# GLIB_CFLAGS = $$(pkg-config --cflags glib-3.0)
# PANGO_CFLAGS = $$(pkg-config --cflags pango)
# GTK_CFLAGS = $$(pkg-config --cflags gtk+-3.0)
 
# CFLAGS = $(ERROR_CFLAGS) $(GLIB_CFLAGS) $(PANGO_CFLAGS) $(GTK_CFLAGS)

# # Flags pour l'editeur de liens:
# GLIB_LDFLAGS = $$(pkg-config --libs glib-3.0)
# PANGO_LDFLAGS = $$(pkg-config --libs pango)
# GTK_LDFLAGS = $$(pkg-config --libs gtk+-3.0)

# LDFLAGS = $(ERROR_CFLAGS) $(GLIB_LDFLAGS) $(PANGO_LDFLAGS) $(GTK_LDFLAGS)

# $(BINDIR)%.o : $(VUEDIR)%.c
# 	$(CC) $(CFLAGS) -c $< -o $@
# mainVue : $(BINDIR)mainVue.o
# 	$(CC) $(LDFLAGS) -o $@ $<
# 	./$@

# vue :
# 	./mainVue 

