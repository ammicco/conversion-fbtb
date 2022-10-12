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

static void lower_10(int number, int source_base, int dest_base){
    printf("(%d)%d = (%d)%d\n", 
        number, 
        source_base, 
        base_to_base(number, source_base, dest_base), 
        dest_base
    );
}

static void upper_10(char *number, int source_base, int dest_base){
    if(source_base < 11 && dest_base > 10){
        printf("(%s)%d = (%s)%d\n", 
            number, 
            source_base,
            decimal_to_base_upper_10(base_to_base(atoi(number), source_base, 10), dest_base),
            dest_base
        );
    }else{
        if(dest_base < 11){
            printf("(%s)%d = (%d)%d\n", 
                number, 
                source_base,
                decimal_to_base(base_upper_10_to_decimal(number, source_base), dest_base),
                dest_base
            );
        }else{
            printf("(%s)%d = (%s)%d\n", 
                number, 
                source_base,
                decimal_to_base_upper_10(base_upper_10_to_decimal(number, source_base), dest_base),
                dest_base
            );
        }
    }
}

int main(int argc, char **argv){
    int source_base = atoi(argv[2]), dest_base = atoi(argv[3]);

    if(argc < 4){
        usage();

        return -1;
    }

    if(source_base < 2 || dest_base < 2){
        base_error();

        return -1;
    }

    if(source_base < 11 && dest_base < 11){
        if(is_actual_this_base(atoi(argv[1]), source_base) == -1){
            math_err();

            return -1;
        }

        lower_10(atoi(argv[1]), source_base, dest_base);
    }else{
        if(is_actual_this_base_upper_10(argv[1], source_base) == -1){
            math_err();

            return -1;
        }

        upper_10(argv[1], source_base, dest_base);
    }

    return 0;
}