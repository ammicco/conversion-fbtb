#include <stdio.h>
#include <stdlib.h>

#include "convert_base.h"

static void usage(void){
    printf("Usage: ./convert \"source number\" \"source base\" \"dest base\".\n");
}

static void math_err(void){
    printf("Math error! Your number isn't in that base.\n");
}

static void base_error(void){
    printf("Can't use that base.\n");
}

int main(int argc, char **argv){
    if(argc < 4){
        usage();

        return -1;
    }

    if(atoi(argv[2]) == 1 || atoi(argv[2]) == 0 
    || atoi(argv[3]) == 1 || atoi(argv[3]) == 0
    || atoi(argv[2]) > 10 || atoi(argv[2]) > 10 
    || atoi(argv[3]) > 10 || atoi(argv[3]) > 10){
        base_error();

        return -1;
    }

    if(is_actual_this_base(atoi(argv[1]), atoi(argv[2])) == -1){
        math_err();

        return -1;
    }

    printf("(%d)%d = (%d)%d\n", 
        atoi(argv[1]), 
        atoi(argv[2]), 
        base_to_base(atoi(argv[1]), 
        atoi(argv[2]), 
        atoi(argv[3])), 
        atoi(argv[3])
    );

    return 0;
}