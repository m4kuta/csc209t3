#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>      
#include <sys/types.h>  
#include <sys/wait.h>  
#include <string.h>

struct loc {
        int x;
        int y;
        char *name;
};

struct loc *fun(struct loc a) {
        struct loc *b = malloc(sizeof(struct loc));
        b->x = a.x + 3;
        b->y  = a.y + 32;
        b->name = "here";
        return b;
}

struct house {
        char owner[80];
      	struct loc *location;
   };

int main() {
        struct loc home;
        home.x = 3;
        home.y = 5;
        home.name = "there";

        struct loc *away;
        away = fun(home);

        struct house house;
        printf("%ld\n", sizeof(house));
}