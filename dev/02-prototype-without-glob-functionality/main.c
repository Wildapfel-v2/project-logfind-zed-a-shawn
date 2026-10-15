#include <stdio.h>
#include "dbg.h"
#include "string_utils.h"

const char *DUMMY_LOGFIND_PATH = "/var/home/max-inspiron/Workbench/learn-c-the-hard-way-revisited/v2/exercises/part04-projects/ex26-project-logfind/dev/02-prototype-without-glob-functionality/logfind_example.txt";

int main(){

    log_info("hello world");
    
    FILE *fp;
    fp = fopen(DUMMY_LOGFIND_PATH, "r");
    char ** lines = readlines(fp);

    log_info("%s", lines[0]);
    log_info("%s", lines[1]);
    log_info("%s", lines[2]);
    log_info("%s", lines[3]);

    return 0;
}