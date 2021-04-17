#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>      
#include <sys/types.h>  
#include <sys/wait.h>  
#include <string.h>
#include <math.h>
#include <fcntl.h>
#include <sys/stat.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int fds[2][2];

int main() {
    int num_procs;  // the number of child processes
    fds[num_procs][2];  // assume these descriptors are open correctly
    fd_set allfds;
    FD_ZERO(&allfds);
    int maxfd = 0;
    int sum = 0;

    // TODO initialization if needed
    fd_set readyfds;
    char buf[sizeof(int)];

    // Read from the pipes connected to the child processes
    while(!is_empty(&allfds)) {
        // TODO 
        readyfds = allfds;
        select(maxfd+1, &readyfds, NULL, NULL, NULL);
        
        for (int i = 0; i < num_procs; i++) {
            if (FD_ISSET(fds[i][0], &readyfds)) {
                if (read(fds[i][0], buf, 256) == 0) {
                    fprintf(stderr, "fd %d is closed.\n", i);
                    FD_CLR(fds[i][0], &allfds);
                } else {
                    sum += strtol(buf, NULL, 10);
                }
            }
        }
    }

    printf("Sum is %d\n", sum);
}
