#include <stdio.h>
#include "mystring.h"

void mystrcpy(char *destination,const char *source)
{
    int i;
    for(i=0;source[i]!='\0';i++)
    {
        destination[i]=source[i];
    }
    destination[i]='\0';
}
///////////////////////////////////////////////////////////////
void mystrncpy(char *destination,const char *source,size_t n)
{
    int i;
    for(i=0;i<n&&source[i]!='\0';i++)
    {
        destination[i]=source[i];
    }
    destination[i]='\0';
}
///////////////////////////////////////////////////////////////
char *mystrcat(char * s1, const char *s2)
{
    int i,j;
    i=0;
    while(s1[i]!='\0')
    {
        i++;
    }
    for(j=0;s2[j]!='\0';j++)
    {
        s1[i]=s2[j];
        i++;
    }
    s1[i]='\0';
}
///////////////////////////////////////////////////////////////
void mystrncat(char *destination,const char *source,size_t n)
{
    int i,j;
    for(i=0;destination[i]!='\0';i++);
    for(j=0;j<n&&source[j]!='\0';j++)
    {
        destination[i]=source[j];
        i++;
    }
    destination[i]='\0';
}
///////////////////////////////////////////////////////////////
int mystrcmp(const char *str1,const char *str2)
{
    int i;
    for(i=0;str1[i]!='\0'&&str2[i]!='\0';i++)
    {
        if(str1[i]!=str2[i])
            break;
    }
    if(str1[i]=='\0'&&str2[i]=='\0')
        return 0;
    else
        return 1;
}
///////////////////////////////////////////////////////////////
int mystrncmp(const char *s1,const char *s2,size_t n)
{
    int k;
    for(k=0;k<n&&s1[k]!='\0'&&s2[k]!='\0';k++)
    {
        if(s1[k]!=s2[k])
            break;
    }
    if(k==n||(s1[k]=='\0'&&s2[k]=='\0'))
        return 0;
    else
        return 1;
}
///////////////////////////////////////////////////////////////



