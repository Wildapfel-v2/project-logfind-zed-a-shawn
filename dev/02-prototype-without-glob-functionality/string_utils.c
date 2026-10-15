#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"

int get_n_lines(FILE *fp){
    char c;
    int counter = 0;
    while (c != EOF){
        c = fgetc(fp);
        if (c == '\n'){
            counter++;
        }
    }
    rewind(fp);         // important, otherwise end of the file and you can reach any information aynmore
    return counter + 1; // for the EOF, doesnt need to have a \n symbol 
}

char **readlines(FILE *fp){

    int n_lines = get_n_lines(fp);
    char *line;
    
    char **lines = malloc(sizeof(char*)*n_lines);

    for (int i = 0; i < n_lines; i++){
        line = readline(fp);
        lines[i] = line;
        if (line == NULL) break;
    }

    rewind(fp);         // same here ... 
    return lines;

}

char *readline(FILE *fp){

    char c;
    int counter = 0; 
    fpos_t pos_start;
    fpos_t pos_end;
    int rc = fgetpos(fp, &pos_start);

    while (c != EOF){
        c = fgetc(fp);

        if (c == '\n'){
            break;
        }
        counter++;
    }

    if (counter == 0) return NULL;

    rc = fgetpos(fp, &pos_end);
    fsetpos(fp, &pos_start);
    char *str_buf = malloc(sizeof(char) * (counter+1));
    fread(str_buf, sizeof(char) * counter, 1, fp);
    str_buf[counter] = '\0';
    fsetpos(fp, &pos_end);
    
    return str_buf;

}