int main(void)
{
    //////////////////////////////////////////////////
    char sourc[20],destinatio[20];
    printf("\nInsira a string:");
    gets(sourc);
    printf("\nA string e:%s",sourc);//cpy
    strcpy(destinatio,sourc);
    printf("\nA string de destino é:%s",destinatio);
    //////////////////////////////////////////////////
    int n33;
    char source33[30],destination33[30];
    printf("\nInsira a string");
    gets(source33);
    printf("\nDigite o comprimento do número da string a ser copiada:");//strncpy
    scanf("%d",&n33);
    printf("\nA string e:%s",source33);
    strncpy(destination33,source33,n33);
    printf("\nA string de destino é:%s",destination33);
    //////////////////////////////////////////////////
    char source[20],destination[20];
    printf("\nInsira a string:");
    gets(destination);
    printf("\nInsira a string");//CAT
    gets(source);
    strcat(destination,source);
    printf("\nA concatenacao da string:%s",destination);
    //////////////////////////////////////////////////
    char source1[50],destination1[50];
    int n;
    printf("\nInsira a string:");
    gets(destination1);

    printf("\nInsira a string");//STRNCAT
    gets(source1);
    printf("\nInsira o comprimento para concatenar:");
    scanf("%d",&n);
    strncat(destination1,source1,n);
    printf("\nA concatenacao da string:%s",destination1);
    ////////////////////////////////////////////////////
    char str1[30],str2[30];
    int ch;
    printf("\nEnter string 1:");
    gets(str1);
    printf("\nEnter string 2:");//STRCMP
    gets(str2);
    ch=strcmp(str1,str2);
    if(ch==0)
        printf("\nAs duas sao iguais");
    else
        printf("\nAs strings sao diferentes");
    //////////////////////////////////////////////////////
    char str11[50],str22[50];
    int n1,ch1;
    printf("\nEnter string 1:");
    gets(str11);
    printf("\nEnter string 2:");//STRNCMP
    gets(str22);
    printf("\nEnter comprimento:");
    scanf("%d",&n1);
    ch1=strncmp(str11,str22,n1);
    if(ch1==0)
        printf("\nAs duas sao iguais");
    else
        printf("\nSao diferentes");
    return 0;
}
/*Ouve erros na parte de limpeza do teclado,espero que considere,uma por uma esta correto*/