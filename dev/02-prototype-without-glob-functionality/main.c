#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"
#include "string_utils.h"

const char *DUMMY_LOGFIND_PATH = "/var/home/max-inspiron/Workbench/learn-c-the-hard-way-revisited/v2/exercises/part04-projects/ex26-project-logfind/dev/02-prototype-without-glob-functionality/logfind_example.txt";

int main(int argc, char *argv[]){

    if (argc == 1) {
        log_err("Missing patterns: /main.c ...");
        exit(1);
    }

    int n_patterns = argc - 1;
    argv++;                         // just do the pointer trick, just incremnt by the first strings, which is function call
   
    FILE *fp;
    fp = fopen(DUMMY_LOGFIND_PATH, "r");
    char **lines = readlines(fp);
    int n_lines = get_n_lines(fp);
    for (int i = 0; i < n_lines; i++){

        FILE *fp_logfind_content;
        fp_logfind_content = fopen(lines[i], "r");
        char *line;
        int bool_;
        int dev_c = 0;
        while (dev_c < 20){
            line = readline(fp_logfind_content);
            log_info("%s", line);
            if (line == NULL) break;
            bool_ = patterns_exists(line, n_patterns, argv, "and");
            // if (bool_) 
            log_info("%d", bool_);
            // break;
            dev_c++;
        }
    }

    return 0;
}