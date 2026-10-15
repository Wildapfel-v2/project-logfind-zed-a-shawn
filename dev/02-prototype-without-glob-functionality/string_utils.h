#ifndef STRING_UTILS_H
#define STRING_UTILS_H

int get_n_lines(FILE *fp);

char **readlines(FILE *fp);

char *readline(FILE *fp);

int patterns_exists(char *text, int n_patterns, char *patterns[], char *mode);

int evalute(int *bools, int n_bools, char *mode);

#endif