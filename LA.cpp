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
int Mystrlen(string a);
string Mystrcpy(string a ,string b);
string Mystrcat(string a ,string b);
int Mystrcmp(string a , string b);

int main()
{
    ifstream my_File;
    ofstream my_File1;
    char ch;

    my_File.open("C://Users//User//Desktop//text.txt" , ios::in);
    my_File1.open("C://Users//User//Desktop//text2.txt" , ios::out);
    if (!my_File) {
		cout << "File not created";}
		if (!my_File1) {
		cout << "File not created";}
   while(!my_File.eof()){

   		ch = my_File.get();
        if(isalpha(ch)){
                std::string word = "";
                word += ch;
                char nextchar = my_File.get();
                while(isalpha(nextchar)){
                    word += nextchar;
                    nextchar = my_File.get();
                }
                cout << word;
               bool flag = false;
                    if (checkKeyword(word)==true)
                        {cout << " KEYWORD" <<endl; flag = true;}
                    if (checkPreProcessor(word)==true)
                        {cout << " Preprocessor" <<endl; flag = true;}
                    if (checkHeaderFile(word)==true)
                        {cout << " Headerfile" <<endl; flag = true;}

                if(flag == false){cout << " IDENTIFIER" <<endl;}
                ch = nextchar;
            }
        {if(isPuncuators(ch)==true)
        {
            cout<<ch<<"puncuators"<<endl;

        }
        if(isOperator(ch)==true)
        {
            cout<<ch<<"operators"<<endl;
        }
        }
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

        case '+':
        {return true;}

        case '-':
        {return true;}

        case '*':
        {return true;}

        case '/':
        {return true;}

        case ',':
        {return true;}

        case ';':
        {return true;}

        case '>':
        {return true;}

        case '<':
        {return true;}

        case '=':
        {return true;}

        case '|':
        {return true;}

        case '&':
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

