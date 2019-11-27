NAME =		pathfinder
NAMEA =		libmx.a

CFLAGS =	-std=c11 -Wall -Wextra -Werror -Wpedantic

# --------- Header files ---------
INC =		libmx-path.h
INCI =		$(addprefix inc/, libmx-path.h)

# --------- Source files ---------

MAIN = 		main.c

SRC = 		mx_printerr.c

SRCS =  	$(addprefix src/,\
				main.c				\
				mx_printerr.c		\
			)

# --------- Object files ---------
OBJ = 		mx_printerr.o


all: install clean
install:
	@ make install -sC libmx/
	@ cp $(SRCS) $(INCI) libmx/$(NAMEA) .
	@ clang $(CFLAGS) -c $(SRC) -I $(INC)
	@ clang $(CFLAGS) $(NAMEA) $(MAIN) $(OBJ) -o $(NAME)
	@ mkdir ./obj
	@ mv $(OBJ) ./obj
uninstall:
	@ rm -rf $(NAME) ./obj
	@ make uninstall -sC libmx/
clean:
	@ rm -rf $(INC) $(SRC) $(MAIN) $(NAMEA)
	@ make clean -sC libmx/
reinstall: uninstall all
