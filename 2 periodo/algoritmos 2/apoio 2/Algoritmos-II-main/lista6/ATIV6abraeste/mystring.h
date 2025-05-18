#ifndef mystring_h
#define mystring_h

void mystrcpy(char *destination,const char *source);
void mystrncpy(char *destination,const char *source,size_t n)
char *mystrcat(char * s1, const char *s2);
void mystrncat(char *destination,const char *source,size_t n)
int mystrcmp(const char *s1,const char *s2);
int mystrncmp(const char *s1,const char *s2,size_t n);
#endif