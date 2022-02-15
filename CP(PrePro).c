#include <stdio.h>
int main()
{   FILE *fptr[20];
    FILE *fptr1[20];
    for(int i=0;i<3;i++) //to read from multiple file in a folder
   {char fn[100];
        sprintf(fn,"D:/New folder (2)/file3/New%d.c", i );// it will generate the files name
        if ((fptr[i]= fopen(fn,"r")) == NULL)
        {printf("Error! opening file");
        exit(1);}
    char fn1[100];
        sprintf(fn1,"D:/New folder (2)/file4/New%d.c", i );//to write in multiple file in a folder
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
