#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>      
#include <sys/types.h>  
#include <sys/wait.h>  
#include <string.h>

int main() {
    int foo = 4;
    int bar = 5;
    int *ptr = &bar;
    
    pid_t process = fork();
    if(process == 0) {
        *ptr += foo;
        exit(0);
    } else {
        printf("%d\n", *ptr);
    }
    return 0;
}