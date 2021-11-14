# Variable pour compiler
CC = gcc
CFLAGS = -Wall -g

# Chemin
SRCDIR = src/
BINDIR = bin/
MODELEDIR = src/modele/
VUEDIR = src/vue/

# Flags d'erreurs:
ERROR_CFLAGS = -Wall -W -pedantic
# Flags pour le compilateur:
GLIB_CFLAGS = $$(pkg-config --cflags glib-2.0)
PANGO_CFLAGS = $$(pkg-config --cflags pango)
GTK_CFLAGS = $$(pkg-config --cflags gtk+-2.0)
 
CFLAGS = $(ERROR_CFLAGS) $(GLIB_CFLAGS) $(PANGO_CFLAGS) $(GTK_CFLAGS)

# Flags pour l'editeur de liens:
GLIB_LDFLAGS = $$(pkg-config --libs glib-2.0)
PANGO_LDFLAGS = $$(pkg-config --libs pango)
GTK_LDFLAGS = $$(pkg-config --libs gtk+-2.0)

LDFLAGS = $(ERROR_CFLAGS) $(GLIB_LDFLAGS) $(PANGO_LDFLAGS) $(GTK_LDFLAGS)



## PROGRAMME : 

# Fichier .o
OBJS = $(BINDIR)main.o $(BINDIR)methode.o 
OBJSVUE = $(BINDIR)mainVue.o

all : $(OBJS) $(OBJSVUE) main mainVue

$(BINDIR)%.o : $(MODELEDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BINDIR)%.o : $(VUEDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

main : $(BINDIR)main.o
	$(CC) $< -o $@
	./$@

mainVue : $(BINDIR)mainVue.o
	$(CC) $(LDFLAGS) -o $@ $<
	./$@

clean :
	@ rm $(BINDIR)*.o main mainVue 2> /dev/null || true
	@ echo "cleaning done"