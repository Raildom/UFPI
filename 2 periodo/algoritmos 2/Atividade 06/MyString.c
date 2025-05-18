#include <stdio.h>
#include "MyString.h"

char *mystrcpy(char *s1, const char *s2) {
    char *inicio = s1;
    while(*s2 != '\0') {
        *s1 = *s2;
        s2++;
        s1++;
    }
    *s1 = '\0';
    return inicio;
}

char *mystrncpy(char *s1, const char *s2, int n){
    int i;
    char *inicio = s1;

    for(i = 0; i < n && *s2 != '\0'; i++){
        *s1 = *s2;
        s2++;
        s1++;
    }
    for(; i < n; i++){
        *s1 = '\0';
        s1++;
    }
    *s1 = '\0';
    return inicio;
}

char *mystrcat(char *s1, const char *s2){
    char *inicio = s1;
    while(*s1 != '\0'){
        s1++;
    }
    while(*s2 != '\0'){
        *s1 = *s2;
        s2++;
        s1++;
    }
    *s1 = '\0';
    return inicio;
}


char *mystrncat(char *s1, const char *s2, int n){
    int i;
    char *inicio = s1;

    while(*s1 != '\0'){
        s1++;
    }
    for(i = 0; i < n && *s2 != '\0'; i++){
        *s1 = *s2;
        s2++;
        s1++;
    }
    *s1 = '\0';
    return inicio;
}

int mystrcmp(const char *s1, const char *s2) {
    while (*s1 == *s2) {
        if (*s1 == '\0') {
            return 0;
        }
        s1++;
        s2++;
    }
    if(*s1 == *s2){
        return 0;
    }else if(*s1 < *s2){
        return -1;
    }else{
        return 1;
    }
}

int mystrncmp(const char *s1, const char *s2, int n){
    int i = 0;

    while(i < n && (*s1 != '\0' || *s2 != '\0')){
        if(*s1 != *s2){
            return (*s1 < *s2) ? -1 : 1;
        }
        s1++;
        s2++;
        i++;
    }
    return 0;
}