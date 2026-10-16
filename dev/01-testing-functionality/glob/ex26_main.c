#include <stdio.h>
#include <glob.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    

    glob_t glob_buffer;
    glob("test/*", GLOB_DOOFFS, NULL, &glob_buffer);
    
    // glob_buffer.gl_offs = 2;
    // glob_buffer.gl_pathv[0] = "ls";
    // glob_buffer.gl_pathv[1] = "-l";
    // execvp("ls", &glob_buffer.gl_pathv[0]);
    // printf("%s\n", *(glob_buffer.gl_pathv[0]));
    // glob(".log", 0, ,glob_t_ptr);
    // printf("%p\n", glob_t_ptr);

    printf("hello world\n");
    printf("%d\n", glob_buffer.gl_pathc);
    printf("%s\n", glob_buffer.gl_pathv[0]);
    
    return 0;

}