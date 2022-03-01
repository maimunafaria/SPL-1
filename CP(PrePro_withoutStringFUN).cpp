#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<ctype.h>
using namespace std;
int Mystrlen(string a);
string Mystrcpy(string a ,string b);
string Mystrcat(string a ,string b);
string inputfilename(int i);
string outputfilename(int i);
int main()
{int i;
    ifstream my_file[20];
    ofstream my_file1[20];
    for(i=0;i<3;i++)
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
int Mystrlen(string a)
{
    int i,length=0;
    for(i=0;a[i]!='\0';i++)
    {
        length++;
    }
    return length;
}
string Mystrcpy(string a ,string b)
{
    a=b;
    return a;
}
string Mystrcat(string a ,string b)
{
    a=a+b;
    return a;
}
string inputfilename(int i)
{   int l;
    string ans;
    string a="D:/New folder (2)/file5/New";
    string b=".c";
    string c=to_string(i);
    a=Mystrcat(a,c);
    a=Mystrcat(a,b);
    ans=Mystrcpy(ans,a);
    return ans;}
string outputfilename(int i)
{   int l;
    string ans;
    string a="D:/New folder (2)/file6/New";
    string b=".c";
    string c=to_string(i);
    a=Mystrcat(a,c);
    a=Mystrcat(a,b);
    ans=Mystrcpy(ans,a);
    return ans;}
