#include <stdio.h>
#include "dbg.h"
#include "string_utils.h"

const char *DUMMY_LOGFIND_PATH = "/var/home/max-inspiron/Workbench/learn-c-the-hard-way-revisited/v2/exercises/part04-projects/ex26-project-logfind/dev/02-prototype-without-glob-functionality/logfind_example.txt";

int main(int argc, char *argv[]){


    FILE *fp;
    fp = fopen(DUMMY_LOGFIND_PATH, "r");
    char **lines = readlines(fp);
    int n_lines = get_n_lines(fp);
    for (int i = 0; i < n_lines; i++){

        FILE *fp_logfind_content;
        fp_logfind_content = fopen(lines[i], "r");
        char **log_lines = readlines(fp_logfind_content);
        log_info("%s", log_lines[0]);

    }


    return 0;
}