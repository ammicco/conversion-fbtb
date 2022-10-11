#include "./convert_base.h"
#include <math.h>
#include <stdio.h>

int decimal_to_base(int decimal, int base){
    char *number = malloc(sizeof(char) * base_lenght(decimal, base));
    int r, q = decimal, i = 0;

    do{
        r = q % base; 
        q = q / base; 

        number[i] = (char) r + 48;

        i++;
    }while(q);

    return atoi(reverse(number));     
}

int base_to_decimal(int number, int base){
    int cifra, q = number, i = 0, decimal = 0; 

    do{
        cifra = q % 10; 
        q = q / 10;

        decimal += cifra * pow(base, i);

        i++;
    }while(q);

    return decimal;    
}

int base_to_base(int number, int source_base, int dest_base){
    return source_base == 10 ? 
        decimal_to_base(number, dest_base) : 
        decimal_to_base(base_to_decimal(number, source_base), dest_base); 
}

int base_lenght(int decimal, int base){
    int l = 0, q = decimal; 

    do {
        q = q / base;
        l++;
    }while(q);

    return l;
}

int cifre(int number){
    int l = 0, q = number;

    do{
        q = q / 10;
        l++;
    }while(q);

    return l;
}

int is_actual_this_base(int number, int base){
    int cifra, q = number; 

    do{
        cifra = q % 10; 
        q = q / 10;

        if(cifra >= base){
            return -1;
        }
    }while(q);

    return 0;
}