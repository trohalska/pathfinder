NAME =		pathfinder
NAMEA =		libmx.a
CFLAGS =	-std=c11 -Wall -Wextra -Werror -Wpedantic

# --------- Header files ----------------
INC =		libmxpath.h
INCI =		$(addprefix inc/, libmxpath.h)

# --------- Source files ----------------

MAIN = 		main.c

SRC = 			mx_printerr.c			\
				mx_atoi.c				\
				mx_isdigit.c			\

SRCS =  	$(addprefix src/,			\
				main.c		\
				mx_printerr.c			\
				mx_atoi.c				\
				mx_isdigit.c			\
			)

# --------- Object files ----------------
OBJ = 			mx_printerr.o			\
				mx_atoi.o				\
				mx_isdigit.o

all: install clean
install:
	@ cp $(SRCS) $(INCI) .
	@ clang $(CFLAGS) -c $(SRC) -I $(INC)
	@ clang $(CFLAGS) $(NAMEA) $(MAIN) $(OBJ) -o $(NAME)
	@ mkdir ./obj
	@ mv $(OBJ) ./obj
uninstall:
	@ rm -rf $(NAME) ./obj
clean:
	@ rm -rf $(INC) $(SRC) $(MAIN) 
reinstall: uninstall all
