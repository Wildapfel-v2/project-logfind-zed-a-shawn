#include <stdio.h>
#include <stdlib.h>

const char *DUMMY_LOGFIND_PATH = "/var/home/max-inspiron/Workbench/learn-c-the-hard-way-revisited/v2/exercises/part04-projects/ex26-project-logfind/dev/02-prototype-without-glob-functionality/logfind_example.txt";

int main(int argc, char *argv[]){

    FILE *file_ptr;

    file_ptr = fopen(DUMMY_LOGFIND_PATH, "r");




    printf("hello world\n");

    return 0; 
}