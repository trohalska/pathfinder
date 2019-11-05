#ifndef LIBMXPATH_H
#define LIBMXPATH_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <malloc/malloc.h>
#include "libmx/inc/libmx.h"

//#include <string.h>

void mx_printerr(const char *s);

int mx_atoi(const char *str);
bool mx_isdigit(int c);


//char **read_pic(char *v, int *h, int *w);

#endif
