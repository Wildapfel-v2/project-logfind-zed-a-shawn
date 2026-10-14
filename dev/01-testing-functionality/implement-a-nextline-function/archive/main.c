/*
I tried to manually set the "hidden" attributes in the FILE struct, 
but I bleive that this is bad practice. Since _ (underscores) show 
that they should not be touched

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "dbg.h"


void newline(FILE *fp){

    int *test = malloc(sizeof(int));
    // log_info("%p", fp->_IO_read_ptr);
    // log_info("%p", test);

    char c;
    int counter = 0; 
    int was_it_fetched = 0;

    while (c != EOF){

        c = fgetc(fp);
        if (!was_it_fetched){
            // log_info("hello world");
            // test = &(fp->_IO_read_ptr-1);
            memcpy(test, &fp->_IO_read_ptr, sizeof(int)); // subtract one, because fgetc increments and doesnt expose the first element directly
            // log_info("%c", *test);
            was_it_fetched = 1;
        }

        if (c == '\n'){
            break;
        }
        counter++;
        // log_info("%c", *(fp->_IO_read_ptr-1));
        // log_info("%p", fp->_IO_read_ptr);
        // log_info("%p", test);
        // log_info("%p", fp_start->_IO_read_ptr);
        // log_info("count %d %c", counter, c);
    }
    unsigned char str_buf[counter + 1];
    log_info("%d", counter);
    *fp->_IO_read_ptr = *test;
    for (int i = 0; i < counter; i++){
        str_buf[i] = fgetc(fp);;
        // test++;
        // log_info("%c", str_buf[i]);
        // log_info("%d", i);
    }
    log_info("%s", str_buf);
    // // fp->_IO_read_ptr = NULL;
    // fread(str_buf, sizeof(char) * counter, 1, test);
    // log_info("%s", str_buf);
    // counter = 0;s
    // log_info("%p", test);

    // // // log_info("%d", fp);
    // // rewind(fp);
    // // // log_info("%d", fp);
    // // fread(str_buf, 10 - 1, 1, fp_start);
    // log_info("%s", str_buf);
    // // // assert(str_buf[counter - 1] == '\0');
    // // fp++; //counter; 
    // // log_info("%s", str_buf);
    
    // unsigned char dumb_buf_of_newline_synbol[1];
    // fread(dumb_buf_of_newline_synbol, sizeof(dumb_buf_of_newline_synbol), 1, fp);

    

    // fread(str_buf, sizeof(str_buf) - 1, 1, fp);
    // assert(str_buf[counter - 1] == '\0');
    // // fp++; //counter; 
    // log_info("%s", str_buf);

    // log_info("%d", fp);

    // unsigned char buf[10];
    // fread(buf, sizeof(buf), 1, fp);
    // // log_info("%s", fp)

    // printf("%s\n", str_buf);
    
}


int main(){

    FILE *fp;
    fp = fopen("/var/home/max-inspiron/Workbench/learn-c-the-hard-way-revisited/v2/exercises/part04-projects/ex26-project-logfind/dev/01-testing-functionality/implement-a-nextline-function/test.txt", "r");
    newline(fp);
    newline(fp);
    // newline(fp);
    // newline(fp);
    // newline(fp);



    return 0;

}