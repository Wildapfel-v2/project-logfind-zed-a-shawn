#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_utils.h"
#include "dbg.h"

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

    while (!feof(fp)){
        c = fgetc(fp);
        if (c == '\n'){
            break;
        }
        counter++;
    }
    // using 1 here stops the endless reading i wasn encountering
    if (counter == 1) return NULL; 

    rc = fgetpos(fp, &pos_end);
    fsetpos(fp, &pos_start);
    char *str_buf = malloc(sizeof(char) * (counter+1));
    fread(str_buf, sizeof(char) * counter, 1, fp);
    str_buf[counter] = '\0';
    fsetpos(fp, &pos_end);
    
    return str_buf;

}

int evalute(int *bools, int n_bools, char *mode){
    // since he didnt introduce any fancy math/logic library, 
    // I will just evalute with a loop

    int c = 0;
    for (int i = 0; i < n_bools; i++){
        c += bools[i];
    }

    if (!strcmp(mode, "and")) return (c == n_bools) ? 1 : 0;
    if (!strcmp(mode, "or")) return (c >= 1) ? 1 : 0;

    // log_info("Wrong mode: and | or only. ");
    printf("Wrong mode: and | or only. ");
    exit(1);

}

int patterns_exists(char *text, int n_patterns, char *patterns[], char *mode){

    if (text == NULL) return -1;

    int matched[n_patterns];

    for (int i = 0; i < n_patterns; i++){
        char *pos = strstr(text, patterns[i]);
        if (pos != NULL){ // pattern exists
            matched[i] = 1;
        }
        // else leave the default zeros
    }

    return evalute(matched, n_patterns, mode);
}
