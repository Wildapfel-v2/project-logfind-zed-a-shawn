#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include "dbg.h"
#include "string_utils.h"

const char *DUMMY_LOGFIND_PATH = "/var/home/max-inspiron/Workbench/learn-c-the-hard-way-revisited/v2/exercises/part04-projects/ex26-project-logfind/dev/03-prototype-glob-integration/logfind_example.txt";

int main(int argc, char *argv[]){

    char *MODE = "and"; // 0 is default for and logic

    if (argc == 1) {
        log_err("Missing patterns: /main.c ...");
        exit(1);
    }

    // increment argv pointer according to the start of the first pattern argument
    int n_patterns;
    if (!strcmp(argv[1], "-o")) {
        MODE = "or";
        n_patterns = argc - 2;
        argv++;
        argv++;
    }
    else {
        n_patterns = argc - 1;
        argv++;                         
    }

    FILE *fp;
    fp = fopen(DUMMY_LOGFIND_PATH, "r");
    char **lines = readlines(fp);
    int n_lines = get_n_lines(fp);
     
    char *line_logifnd;
    glob_t glob_buffer;
    for (int i = 0; i < n_lines; i++){
        
        line_logifnd = lines[i];
        glob(line_logifnd, GLOB_DOOFFS, NULL, &glob_buffer);
    
        for (int j = 0; j < glob_buffer.gl_pathc; j++){
            int l = strlen(glob_buffer.gl_pathv[j]);
            char *fending = glob_buffer.gl_pathv[j]+(l-4);
            if (strcmp(".log", fending)) continue; // exit if not a .log file            
            char *file = glob_buffer.gl_pathv[j];
            char *line;
            int bool_;
            FILE *fp_line;
            fp_line = fopen(file, "r");
            while (1){
                line = readline(fp_line);
                if (line == NULL) break;
                bool_ = patterns_exists(line, n_patterns, argv, MODE);
                if (bool_) printf("%s\n", line);
            }
        }
    }

    return 0;
}