NAME =		pathfinder

CFLAGS =	-std=c11 -Wall -Wextra -Werror -Wpedantic

# --------- Header files ----------------
INC =		libmx.h
INCI =		$(addprefix inc/, 			\
			libmx.h)

# --------- Source files ----------------

SRC = 		pf_main.c mx_create_dex_matrix.c mx_deijkstra.c mx_get_all_paths.c mx_get_arr_islands.c mx_get_matrix.c mx_pf_errors.c mx_pf_split.c mx_printpaths.c

SRCS =  	$(addprefix src/,			\
			pf_main.c mx_create_dex_matrix.c mx_deijkstra.c mx_get_all_paths.c mx_get_arr_islands.c mx_get_matrix.c mx_pf_errors.c mx_pf_split.c mx_printpaths.c)

# --------- Object files ----------------
OBJ = 		pf_main.o mx_create_dex_matrix.o mx_deijkstra.o mx_get_all_paths.o mx_get_arr_islands.o mx_get_matrix.o mx_pf_errors.o mx_pf_split.o mx_printpaths.o


# ---------------------------------------
all: install uninstall

install:
	@ make install -sC libmx/
	@ cp $(SRCS) $(INCI) .
	@ clang $(CFLAGS) -c $(SRC)
	@ clang $(CFLAGS) $(OBJ) libmx/libmx.a -o $(NAME)
	@ mkdir ./obj
	@ mv $(OBJ) ./obj

uninstall:
	@ make uninstall -sC libmx/
	@ rm -rf $(INC) $(SRC) ./obj

clean: uninstall
	@ make clean -sC libmx/
	@ rm -rf $(NAME)
	
reinstall: clean all
