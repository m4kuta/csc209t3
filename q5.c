#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>      
#include <sys/types.h>  
#include <sys/wait.h>  
#include <string.h>
#include <math.h>
#include <fcntl.h>
#include <sys/stat.h>

//* gcc q5.c -o q5 -Wall -g -std=gnu99

int flag = 0;

void handler(int code) {
    fprintf(stderr, "Handler start\n");
    /* D */
    kill(getpid(), SIGQUIT); //!
    if(flag){
        // assume the open succeeds
        int fd = open("error.out", O_WRONLY | O_CREAT);
        dup2(fd, fileno(stderr));
    }
 
    fprintf(stderr,"Handler end\n");
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGQUIT);

    fprintf(stderr, "Initial\n");
    /* A */
    sigaction(SIGTERM, &sa, NULL);

    fprintf(stderr, "First\n");
    /* B */
    flag = 1;
    /* C */
    kill(getpid(), SIGTERM); //!
    fprintf(stderr, "Done\n");
    return 0;
}


// int flag = 0;

// void handler(int code) {
//     fprintf(stderr, "Handler start\n");
    
//     /* D */
//     printf("Sleeping at D for 5 seconds\n");
//     sleep(5);
//     printf("Done sleeping\n");

//     if(flag){
//         // assume the open succeeds
//         int fd = open("error.out", O_WRONLY | O_CREAT);
//         dup2(fd, fileno(stderr));
//     }
 
//     fprintf(stderr,"Handler end\n");
// }

// int main() {
//     struct sigaction sa;
//     sa.sa_handler = handler;
//     sigemptyset(&sa.sa_mask);
//     sigaddset(&sa.sa_mask, SIGQUIT);

//     fprintf(stderr, "Initial\n");

//     /* A */
//     printf("Sleeping at A for 5 seconds\n");
//     sleep(5);
//     printf("Done sleeping\n");

//     sigaction(SIGTERM, &sa, NULL);

//     fprintf(stderr, "First\n");

//     /* B */
//     printf("Sleeping at B for 5 seconds\n");
//     sleep(5);
//     printf("Done sleeping\n");

//     flag = 1;
//     /* C */
//     printf("Sleeping at C for 5 seconds\n");
//     sleep(5);
//     printf("Done sleeping\n");

//     fprintf(stderr, "Done\n");
//     return 0;
// }