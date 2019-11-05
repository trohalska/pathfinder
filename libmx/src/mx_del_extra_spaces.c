#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
	if (!str) return malloc(0);

	char *n = mx_strtrim(str);

	int kwl = 0;
	int w = mx_count_words_isspace(str, &kwl);

	char *t = mx_strnew(kwl + w - 2);

	int i = 0;
	int j = 0;
	while (n[i]) {
		while (!mx_isspace(n[i]) && n[i]) {
			t[j] = n[i];
			i++;
			j++;
		}
		if (n[i]) {
			t[j] = ' ';
			j++;
		}
		else t[j] = '\0';
		while (mx_isspace(n[i]) && n[i]) {
			i++;
		}
	}	
	free(n);
	return t;
}
