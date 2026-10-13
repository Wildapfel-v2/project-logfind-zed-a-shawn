#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

const char *DUMMY_LOGFIND_PATH = "/var/home/max-inspiron/Workbench/learn-c-the-hard-way-revisited/v2/exercises/part04-projects/ex26-project-logfind/dev/02-prototype-without-glob-functionality/logfind_example.txt";
const int READ_BUF_SIZE = 500;  // arbitrary
const int N_DUMMIES = 3;        // this will be more dynamic

void Prototype_read_files_from_logfind(const char *logfind_path){

    FILE *file_ptr;
    char *files[N_DUMMIES];
    
    for (int i = 0; i < N_DUMMIES; i++){
        files[i] = malloc(sizeof(char) * READ_BUF_SIZE);
        // if (!files){
            check_mem(files[i]);
            // }
            // printf("%d\n", files[i]);
            // check_mem(files[i]); // TODO: WHy do i get an error here. pointer are declared ?!?!?!
        }
        // check(file_ptr, "i dont know");
        
    char read_buf[READ_BUF_SIZE];
    
    // file_ptr = fopen(logfind_path, "r");
    // check(file_ptr, "hello world");
 
//     int rc;
//     while (rc = fread(read_buf, READ_BUF_SIZE, 1, file_ptr)){ // if zero its EOF 
//         printf("%s\n", read_buf);
//     }
//     printf("%d\n", rc);
    
error:
    // for (int i = 0; i < N_DUMMIES; i++) {
    //     if (files[i]) free(files[i]);
    // }
    exit(1);

}

void Prototype_read_content_from_log_file(const char *log_path){
    ;
}

void short_dbg_checker(){

    char *block[N_DUMMIES];
    block[0] = malloc(sizeof(char) * READ_BUF_SIZE);
    check_mem(block);
    printf("hello world\n");
    error:
    exit(1);

}



int main(int argc, char *argv[]){
    
    // Prototype_read_files_from_logfind(DUMMY_LOGFIND_PATH);
    short_dbg_checker();
    return 0; 
    
}