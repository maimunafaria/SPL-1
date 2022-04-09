
#include <vector>
using namespace std;

    vector<string>variable[20];
    vector<string>loop[20];
    vector<string>condition[20];

int isDigit(char ch)
{

    if(ch>=48 && ch<=57)
    {return 0;}
    else
    {return 1;}
}

int isAlpha(char ch)
{

    if(ch>=65 && ch<=90)
    {return 0;}
    else if(ch>=97 && ch<=122)
    {return 0;}
    else
    {return 1;}
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
    if ( Mystrcmp(str, "else")==0
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
    if (Mystrcmp(str, "stdio.h")==0
        ||Mystrcmp(str, "conio.h")==0
        ||Mystrcmp(str, "math.h")==0
        ||Mystrcmp(str, "stdlib.h")==0
        ||Mystrcmp(str, "string.h")==0 )
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
bool checkPrintf(string str)
{
    if (Mystrcmp(str, "printf")==0)
        {
                return true;
        }
    else
    {
        return false;
    }
}

bool checkScanf(string str)
{
    if (Mystrcmp(str, "scanf")==0)
        {
                return true;
        }
    else
    {
        return false;
    }
}
bool checkLoop(string str)
{
    char* token = "Empty";
    if (Mystrcmp(str, "for")==0
        || Mystrcmp(str, "while")==0)
        {
                return true;
        }
    else
    {
        return false;
    }
}
bool checkCondition(string str)
{
    char* token = "Empty";
    if (Mystrcmp(str, "if")==0)
        {
                return true;
        }
    else
    {
        return false;
    }
}
bool isBracket(char x)
{
    switch (x)
    {   case '(':
        {return true;}

        default:
        {return false;}
    }
}


void lexicalAnalysis(string name)
{   char ch1;
    string hashFile;
    string output2;
    ifstream my_File[20];
    ofstream my_File1[20];

    char ch;
    int i,j;
    for(i=0;i<5;i++){
    my_File[i].open(output2=outputfilename(name,i), ios::in);

    if (!my_File[i]) {
		cout << "File not created";
		break;}
    my_File1[i].open(hashFile=hashfilename(name,i) , ios::out);
		if (!my_File1[i]) {
		cout << "File not created";}
   while(!my_File[i].eof()){

   		ch = my_File[i].get();
   		 if((isDigit(ch))==0){
                std::string word = "";
                word += ch;
                char nextchar = my_File[i].get();
                while((isDigit(nextchar))==0||
                       nextchar=='.'){
                    word += nextchar;
                    nextchar = my_File[i].get();
                }
            //   cout << word<< "number "<<endl;
                            my_File1[i]<< "_NUM";
                ch = nextchar;
            }
   		 if((isAlpha(ch))==0){
                std::string word = "";
                word += ch;
                char nextchar = my_File[i].get();
                while((isAlpha(nextchar))==0||
                      (isDigit(nextchar))==0 ||
                       nextchar=='_'||
                       nextchar=='.'){
                    word += nextchar;
                    nextchar = my_File[i].get();
                }
            //   cout << word;
               bool flag = false;
                    if (checkKeyword(word)==true)
                      {//cout << " KEYWORD" <<endl;
                      flag = true;

                          my_File1[i]<< "_KW";
                           ch = nextchar;
                      }
                    if (checkPreProcessor(word)==true)
                       {//cout << " Preprocessor" <<endl;
                        flag = true;

                            my_File1[i]<< "_PP";
                             ch = nextchar;
                       }
                    if (checkHeaderFile(word)==true)
                        {//cout << " Headerfile" <<endl;
                        flag = true;

                            my_File1[i]<< "_HF";
                             ch = nextchar;
                        }
                    if (checkLoop(word)==true)
                        {//cout << " Loop" <<endl;
                            flag = true;

                            my_File1[i]<< "_LP";
                            loop[i].push_back(word);
                             ch = nextchar;
                        }
                        if (checkCondition(word)==true)
                        {//cout << " Condition" <<endl;
                            flag = true;

                            my_File1[i]<< "_CN";
                            condition[i].push_back(word);
                             ch = nextchar;
                        }
                    if (checkPrintf(word)==true)
                      {//cout << " printf" <<endl;
                            ch1= my_File[i].get();
                                while((ch1= my_File[i].get())!=';')
                                {
                                    ;
                                }
                            flag = true;

                            my_File1[i]<< "_PK";

                            }
                    if (checkScanf(word)==true)
                      {//cout << " scanf" <<endl;
                            ch1= my_File[i].get();
                                while((ch1= my_File[i].get())!=';')
                                {
                                    ;
                                }
                            flag = true;

                            my_File1[i]<< "_SK";

                            }


                if(flag == false)
                    {//cout << " IDENTIFIER" <<endl;

                            my_File1[i]<< "_ID";
                             variable[i].push_back(word);
                             ch = nextchar;
                    }

            }
        {if(isPuncuators(ch)==true)
        {
    //      cout<<ch<<"puncuators"<<endl;
                                    my_File1[i]<< "_PUN";

        }
        if(isOperator(ch)==true)
        {
     //      cout<<ch<<"operators"<<endl;
                                     my_File1[i]<< "_OP";
        }
        if(isBracket(ch)==true)
        {
    //      cout<<ch<<"Puncuators"<<endl;
                                     my_File1[i]<< "_PUNB";
        }
        }
}
    my_File[i].close();
    my_File1[i].close();
}


}
int numberOfLoop(int i)
{
    return loop[i].size();
}
int numberOfCondition(int i)
{
    return condition[i].size();
}
int numberOfVariable(int i)
{
    return variable[i].size();
}

