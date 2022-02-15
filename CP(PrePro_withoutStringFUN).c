#include <stdio.h>

int mystrlen(char *a);
char* mystrcpy(char* a, char* b);
char* mystrcat(char* a, char* b);
char *inputfilename(int i);
char *outputfilename(int i);
int main()
{   FILE *fptr[20];
    FILE *fptr1[20];
    for(int i=0;i<3;i++) //to read from multiple file in a folder
   {char fn[100];
        strcpy(fn,inputfilename(i));// it will generate the files name
        if ((fptr[i]= fopen(fn,"r")) == NULL)
        {printf("Error! opening file");
        exit(1);}
    char fn1[100];
       strcpy(fn1,outputfilename(i));//to write in multiple file in a folder
        if((fptr1[i] = fopen(fn1,"w")) == NULL)
        {printf("Error!");
        exit(1);}
    char ch,a,b,c;
    while ((ch = fgetc(fptr[i]))!= EOF)
    {   if(ch== '/') //to check if it is a comment
            {a=fgetc(fptr[i]);
            if(a=='/')
                {while((b=fgetc(fptr[i]))!=EOF) // single line comment
                    {if(b=='\n')
                        {break;}}}
            else if (a=='*')        // multiple line comment
                {while((c=fgetc(fptr[i]))!=EOF)
                    {if(c=='*')
                    {char d =fgetc(fptr[i]);
                        if(d=='/')
                        {break;}}}}
            else
            {fputc(ch, fptr1[i]);}}
        else if(ch== '\n')//deleting newline
            {{}}
        else if(ch== '\t')//deleting tab
            {{}}
        else
            {fputc(ch, fptr1[i]);}}
    fclose(fptr1[i]);
    fclose(fptr[i]);}
return 0;}
int mystrlen(char *a)
{int l,i;
    for(i=0;a[i]!='\0';i++)
    {l++;}
    return l;}
char* mystrcpy(char* a, char* b)
{int i;
    if (a == NULL){return NULL;}
    for(i=0;*b!='\0';i++)
    {*a= *b;
    a++;
    b++;}
    *a='\0';
    return (char *)a;}
char* mystrcat(char* a, char* b)
{int i;
    a = a + strlen(a);
    for(i=0;*b!= '\0';i++)
    {*a=*b;
    a++;
    b++;}
    *a = '\0';
    return (char *)a;}
char *inputfilename(int i)
{int l;
    char *ans;
    char a[40]="D:/New folder (2)/file3/New";
    char b[5]=".c";
    char c[5];
    itoa(i,c,10);
    mystrcat(a,c);
    mystrcat(a,b);
    l=mystrlen(a);
    ans=malloc(l*sizeof(char));
    mystrcpy(ans,a);
    return (char *)ans;}
char *outputfilename(int i)
{int l;
    char *ans;
    char a[40]="D:/New folder (2)/file4/New";
    char b[5]=".c";
    char c[5];
    itoa(i,c,10);
    mystrcat(a,c);
    mystrcat(a,b);
    l=mystrlen(a);
    ans=malloc(l*sizeof(char));
    mystrcpy(ans,a);
    return (char *)ans;}
