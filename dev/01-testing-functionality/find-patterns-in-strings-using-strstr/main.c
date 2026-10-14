#include <stdio.h>
#include <string.h>

int main(){

    // testing the functionality
    char *text = "hello world, this is just for testing ...";
    char *pattern = "just";
    char *return_a_char_pointer = strstr(text, pattern);                        // find first occurence
    printf("%s\n", return_a_char_pointer);                                      // outputs: just for testing ...

    // evaluating pointer arimethic
    printf("%d\n", text);                                                       // like I assumed, the return pointer is just    
    printf("%d\n", return_a_char_pointer);                                      // the xbytes furhter until first occurence (so thats nice)

    // evaluate no matches
    char *no_match_pattern = "hose";
    char *return_a_char_pointer_no_match = strstr(text, no_match_pattern);       
    printf("%p\n", return_a_char_pointer_no_match);                             // as I assumed its a null pointer

    return 0;

}