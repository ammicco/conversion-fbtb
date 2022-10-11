#define MAX_SEG 1000

int count_char(char *str, char sig);            /* return the count of a char in a string */
char **split(char *str, char divider);          /* split a string and return an array of strings contains the splitted original string */ 
char *reverse(char *str);                       /* reverse a string */
char *substr(char *str, int start, int end);    /* return a substring */ 