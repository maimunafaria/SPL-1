#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;
bool isPuncuators(char x);
bool isOperator(char x);
bool checkKeyword(string str);
bool checkPreProcessor(string str);
bool checkHeaderFile(string str);
int Mystrcmp(string a , string b);
int Mystrlen(string a);
string Mystrcpy(string a ,string b);
string Mystrcat(string a ,string b);
string inputfilename(int i);
string outputfilename(int i);
string hashfilename(int i);

int main()
{

    int i;
    ifstream my_file[20];
    ofstream my_file1[20];
    ifstream my_File[20];
    ofstream my_File1[20];
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
    string hashFile;
    string output2;
    my_File[i].open(output2=outputfilename(i), ios::in);
    my_File1[i].open(hashFile=hashfilename(i) , ios::out);
    if (!my_File[i]) {
		cout << "File not created";}
		if (!my_File1[i]) {
		cout << "File not created";}
   while(!my_File[i].eof()){

   		ch = my_File[i].get();
        if(isalpha(ch)){
                std::string word = "";
                word += ch;
                char nextchar = my_File[i].get();
                while(isalpha(nextchar)){
                    word += nextchar;
                    nextchar = my_File[i].get();
                }
               cout << word;
               bool flag = false;
                    if (checkKeyword(word)==true)
                      {cout << " KEYWORD" <<endl; flag = true;

                          my_File1[i]<< "_Keyword";
                      }
                    if (checkPreProcessor(word)==true)
                       {cout << " Preprocessor" <<endl; flag = true;

                            my_File1[i]<< "_PreProcessor";
                       }
                    if (checkHeaderFile(word)==true)
                        {cout << " Headerfile" <<endl; flag = true;

                            my_File1[i]<< "_HeaderFile";
                        }

                if(flag == false)
                    {cout << " IDENTIFIER" <<endl;

                            my_File1[i]<< "_Identifier";
                    }
                ch = nextchar;
            }
        if(isdigit(ch)){
                std::string word = "";
                word += ch;
                char nextchar = my_File[i].get();
                while(isdigit(nextchar)){
                    word += nextchar;
                    nextchar = my_File[i].get();
                }
               cout << word<< "number "<<endl;
                            my_File1[i]<< "_Number";
                ch = nextchar;
            }
        {if(isPuncuators(ch)==true)
        {
          cout<<ch<<"puncuators"<<endl;
                                    my_File1[i]<< "_Puncuators";

        }
        if(isOperator(ch)==true)
        {
           cout<<ch<<"operators"<<endl;
                                     my_File1[i]<< "_Operators";
        }
        }
}
    my_File[i].close();
    my_File1[i].close();
}

}

bool isOperator(char x)
{
    switch (x)
    {
        case '+':
        {return true;}

        case '-':
        {return true;}

        case '*':
        {return true;}

        case '/':
        {return true;}

        case '|':
        {return true;}

        case '&':
        {return true;}

        case '>':
        {return true;}

        case '<':
        {return true;}

        case '=':
        {return true;}

        case '%':
        {return true;}

        case '^':
        {return true;}

        case '!':
        {return true;}

        default:
        {return false;}
    }
}
bool isPuncuators(char x)
{
    switch (x)
    {
        case '#':
        {return true;}

        case '.':
        {return true;}

        case '(':
        {return true;}

        case ')':
        {return true;}

        case '[':
        {return true;}

        case ']':
        {return true;}

        case '{':
        {return true;}

        case '}':
        {return true;}

        case ',':
        {return true;}

        case ';':
        {return true;}

        case '"':
        {return true;}

        default:
        {return false;}
    }
}

bool checkKeyword(string str)
{
    if (Mystrcmp(str, "if")==0
        || Mystrcmp(str, "else")==0
        ||Mystrcmp(str, "while")==0
         || Mystrcmp(str, "do")==0
        ||Mystrcmp(str, "break")==0
        ||  Mystrcmp(str, "continue")==0
        || Mystrcmp(str, "int")==0
        || Mystrcmp(str, "double")==0
        || Mystrcmp(str, "float")==0
        || Mystrcmp(str, "return")==0
        || Mystrcmp(str, "char")==0
        || Mystrcmp(str, "case")==0
        || Mystrcmp(str, "long")==0
        || Mystrcmp(str, "short")==0
        || Mystrcmp(str, "typedef")==0
        || Mystrcmp(str, "switch")==0
        || Mystrcmp(str, "unsigned")==0
        || Mystrcmp(str, "void")==0
        || Mystrcmp(str, "static")==0
        || Mystrcmp(str, "struct")==0
        || Mystrcmp(str, "sizeof")==0
        || Mystrcmp(str,"long")==0
        || Mystrcmp(str, "volatile")==0
        || Mystrcmp(str, "typedef")==0
        || Mystrcmp(str, "enum")==0
        || Mystrcmp(str, "const")==0
        || Mystrcmp(str, "union")==0
        || Mystrcmp(str, "extern")==0
        || Mystrcmp(str,"bool")==0)
        {
            return true;
        }
    else
    {
        return false;
    }
}

bool checkHeaderFile(string str)
{
    if (Mystrcmp(str, "stdio")==0
        ||Mystrcmp(str, "conio")==0
        ||Mystrcmp(str, "math")==0
        ||Mystrcmp(str, "stdlib")==0
        ||Mystrcmp(str, "string")==0 )
        {
            return true;
        }
    else
    {
        return false;
    }

}
bool checkPreProcessor(string str)
{
    char* token = "Empty";
    if (Mystrcmp(str, "include")==0
        || Mystrcmp(str, "define")==0)
        {
                return true;
        }
    else
    {
        return false;
    }
}

int Mystrcmp(string a , string b)
{
    int x = a.compare(b);
    if (x != 0)
    {
        return 1;
    }
    else
        {
            return 0;
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
string hashfilename(int i)
{   int l;
    string ans;
    string a="D:/New folder (2)/file7/New";
    string b=".c";
    string c=to_string(i);
    a=Mystrcat(a,c);
    a=Mystrcat(a,b);
    ans=Mystrcpy(ans,a);
    return ans;}
