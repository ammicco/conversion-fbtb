#include "./manipulate_string.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int count_char(char *str, char sig){
    int i, counter = 0, len = strlen(str);

    for(i = 0; i < len; i++){
        if(str[i] == sig){
            counter++;
        }
    } 

    return counter;
}

char **split(char *str, char divider){
    int i, j = 0, y = 0, len = strlen(str);

    char **tmp = (char **) malloc(sizeof(char *) * (count_char(str, divider) + 1));

    for(i = 0; i < count_char(str, divider) + 1; i++){
        tmp[i] = (char *) malloc(sizeof(char) * len);
        memset(tmp[i], 0, len);
    }

    for(i = 0; i < len; i++){
        if(str[i] != divider){
            tmp[j][y] = str[i];
            y++;
        }else if(str[i] == divider){
            y = 0;
            j++;
        }
    }

    return tmp;
}

char *reverse(char *str){
    int i, j, len = strlen(str); 
    char *tmp = (char *) malloc(sizeof(char) * (len + 1));

    j = len - 1;

    for(i = 0; i < len; i++){
        tmp[i] = str[j];
        j--;
    }

    return tmp;
}

char *substr(char *str, int start, int end){
    int i, j = start; 

    char *sub; 

    if(end > strlen(str) || end < start){
        end = strlen(str);
    }

    sub = (char *) malloc(sizeof(char) * (end - start));

    for(i = 0; i < (end - start); i++){
        sub[i] = str[j];
        j++;
    }

    return sub;
}