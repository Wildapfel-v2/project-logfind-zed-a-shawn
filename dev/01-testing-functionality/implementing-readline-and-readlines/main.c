#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "dbg.h"

char *readline(FILE *fp);


int get_n_lines(FILE *fp){
    char c;
    int counter = 0;
    while (c != EOF){
        c = fgetc(fp);
        if (c == '\n'){
            counter++;
        }
    }
    rewind(fp);         // important !!    
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
    // log_info("%d", counter);
    char *str_buf = malloc(sizeof(char) * (counter+1));
    fread(str_buf, sizeof(char) * counter, 1, fp);
    str_buf[counter] = '\0';
    // log_info("%s", str_buf);
    fsetpos(fp, &pos_end);
    
    return str_buf;

}


int main(){

    FILE *fp;
    fp = fopen("/var/home/max-inspiron/Workbench/learn-c-the-hard-way-revisited/v2/exercises/part04-projects/ex26-project-logfind/dev/01-testing-functionality/implementing-readline-and-readlines/test.txt", "r");
   
    char **lines = readlines(fp);
    log_info("%s", lines[0]);
    log_info("%s", lines[1]);
    log_info("%s", lines[2]);
    log_info("%s", lines[3]);
    log_info("%s", lines[4]);
    log_info("%s", lines[5]);
    log_info("%s", lines[6]);
    // char *test1 = newline(fp);
    // test1 = 
    // newline(fp);
    // newline(fp);
    // newline(fp);
    // newline(fp);
    // newline(fp);
    // newline(fp);
    // newline(fp);
    // newline(fp);
    
    // log_info("%s", test1);

    return 0;

}