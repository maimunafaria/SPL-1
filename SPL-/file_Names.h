#ifndef FILE_NAMES_H_INCLUDED
#define FILE_NAMES_H_INCLUDED
#include"string_Functions.h"



#endif // FILE_NAMES_H_INCLUDED

string inputfilename(int i)
{   int l;
    string ans;
    string a="file5/New";
    string b=".c";
    string c=to_string(i);
    a=Mystrcat(a,c);
    a=Mystrcat(a,b);
    ans=Mystrcpy(ans,a);
    return ans;
    }
string outputfilename(int i)
{   int l;
    string ans;
    string a="file6/New";
    string b=".c";
    string c=to_string(i);
    a=Mystrcat(a,c);
    a=Mystrcat(a,b);
    ans=Mystrcpy(ans,a);
    return ans;
    }
string hashfilename(int i)
{   int l;
    string ans;
    string a="file7/New";
    string b=".c";
    string c=to_string(i);
    a=Mystrcat(a,c);
    a=Mystrcat(a,b);
    ans=Mystrcpy(ans,a);
    return ans;
    }

