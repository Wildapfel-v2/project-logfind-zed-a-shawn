#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

#define READ_BUF_SIZE 500  // this should be obsolete for now 
#define N_DUMMIES 3        // this will be more dynamic

const char *DUMMY_LOGFIND_PATH = "/var/home/max-inspiron/Workbench/learn-c-the-hard-way-revisited/v2/exercises/part04-projects/ex26-project-logfind/dev/02-prototype-without-glob-functionality/logfind_example.txt";

int *Prototype_find_byte_locations_of_newline_chars(const char *logfind_path){

    FILE *file_ptr;
    file_ptr = fopen(logfind_path, "r");
    check(file_ptr, "Failed to open %s\n", logfind_path);

    char c;
    int locs_i = 0;
    int *locs = (int*) malloc(N_DUMMIES * sizeof(int));
    int counter = 0;
    while (c = fgetc(file_ptr)){
        if (c == EOF) {
            locs[locs_i] = counter;
            counter = 0;
            break;
        }    
        counter++;
        if (c == '\n') {
            locs[locs_i++] = counter;
            counter = 0;
        }
    }

    return locs;

    error:
    exit(1);
}

char **Prototype_read_files_from_logfind(const char *logfind_path){

    FILE *file_ptr;
    char *files[N_DUMMIES];
    int *locs = Prototype_find_byte_locations_of_newline_chars(logfind_path);
    int i;

    for (i = 0; i < N_DUMMIES; i++){
        files[i] = (char*) malloc(sizeof(char) * locs[i]); 
        check_mem(files[i]);
    }
    
    file_ptr = fopen(logfind_path, "r");
    check(file_ptr, "Failed to open %s\n", logfind_path);
         
    i = 0;
    int rc;
    while (rc = fread(files[i], locs[i], 1, file_ptr)){ // if zero its EOF 
        if (files[i][locs[i] - 1] == '\n') {
            files[i][locs[i]-1] = '\0';
        }
        i++;
    }

    return files;

    error:
    exit(1);

}


int main(int argc, char *argv[]){
    
    Prototype_read_files_from_logfind(DUMMY_LOGFIND_PATH);
    return 0; 
    
}