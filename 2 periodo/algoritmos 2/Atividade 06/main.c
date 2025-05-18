#include <stdio.h>
#include "MyString.h"

int main(void){
    char s1[100];
    char *s2 = "Hello, guys!";
    char *s3 = "Hello, Guys!";
    char s4[40] = "Hello, ";
    char *s5 = "guys! How are you?";
    char *s6 = " We are fine and you?";

    printf("mystrcpy: %s\n", mystrcpy(s1, s2));
    printf("mystrncpy: %s\n", mystrncpy(s1, s2,  5));
    printf("mystrcmp: %d\n", mystrcmp(s3, s2));
    printf("mystrncmp: %d\n", mystrncmp(s2, s3, 7));
    printf("mystrncmp: %d\n", mystrncmp(s2, s3, 8));
    printf("mystrcat: %s\n", mystrcat(s4, s5));
    printf("mystrncat: %s\n", mystrncat(s4, s6, 12));
    return 0;
}