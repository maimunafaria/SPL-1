#ifndef OUTPUT_FILE_H_INCLUDED
#define OUTPUT_FILE_H_INCLUDED
#include"file_Names.h"



#endif // OUTPUT_FILE_H_INCLUDED
using namespace std;
void outputFileCreate()
{
    int i;
    ifstream my_file[20];
    ofstream my_file1[20];
    ifstream my_File[20];
    ofstream my_File1[20];
    for(i=0;i<5;i++)
	{string input;
    my_file[i].open(input=inputfilename(i), ios::in);
	if (!my_file[i]) {
		cout << "File not created";}
	string output;
    my_file1[i].open(output=outputfilename(i), ios::out);
	if (!my_file1[i]) {
		cout << "File not created";}
    char ch,a,b,c;
    if(my_file[i].is_open())
    while(my_file[i].get(ch))
    {  ;
        if(ch== '/') //to check if it is a comment
            {my_file[i].get(a);
            if(a=='/')
                {if(my_file[i].is_open()) // single line comment
                    {while(my_file[i].get(b))
                        if(b=='\n')
                        {break;}}}
            else if (a=='*')        // multiple line comment
                {if(my_file[i].is_open())
                    {while(my_file[i].get(c))
                        if(c=='*')
                    {char d ;
                    my_file[i].get(d);
                        if(d=='/')
                        {break;}}}}
            else
            {my_file1[i].put(ch);}}
        else if(ch== '\n')//deleting newline
            {{}}
        else if(ch== '\t')//deleting tab
            {{}}
        else
            {my_file1[i].put(ch);}}
    my_file[i].close();
    my_file1[i].close();
}
}
