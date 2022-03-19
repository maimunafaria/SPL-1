#ifndef LEXICAL_ANALYSIS_H_INCLUDED
#define LEXICAL_ANALYSIS_H_INCLUDED



#endif // LEXICAL_ANALYSIS_H_INCLUDED
using namespace std;
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


void lexicalAnalysis()
{   char ch1;
    string hashFile;
    string output2;
    ifstream my_File[20];
    ofstream my_File1[20];
    char ch;
    int i,j;
    for(i=0;i<5;i++){
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
                while(isalpha(nextchar)||
                      isdigit(nextchar) ||
                       nextchar=='_'){
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
                    if (checkPrintf(word)==true)
                      {//cout << " printf" <<endl;
                            ch1= my_File[i].get();
                                while((ch1= my_File[i].get())!=';')
                                {
                                    ;
                                }
                            flag = true;

                            my_File1[i]<< "_TK";

                            }



                if(flag == false)
                    {//cout << " IDENTIFIER" <<endl;

                            my_File1[i]<< "_ID";
                             ch = nextchar;
                    }

            }
        if(isdigit(ch)){
                std::string word = "";
                word += ch;
                char nextchar = my_File[i].get();
                while(isdigit(nextchar)||
                       nextchar=='.'){
                    word += nextchar;
                    nextchar = my_File[i].get();
                }
            //   cout << word<< "number "<<endl;
                            my_File1[i]<< "_NUM";
                ch = nextchar;
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
        }
}
    my_File[i].close();
    my_File1[i].close();

}

}
