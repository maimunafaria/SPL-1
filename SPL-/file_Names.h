
#include"string_Functions.h"
using namespace std;

string inputfilename(string h,int i)
{   int l;
    string ans;
    string a="file5/";
    string b=".c";
    string c=to_string(i);
    a=Mystrcat(a,h);
    a=Mystrcat(a,c);
    a=Mystrcat(a,b);
    ans=Mystrcpy(ans,a);
    return ans;
    }
string outputfilename(string h,int i)
{   int l;
    string ans;
    string a="file6/";
    string b=".c";
    string c=to_string(i);
    a=Mystrcat(a,h);
    a=Mystrcat(a,c);
    a=Mystrcat(a,b);
    ans=Mystrcpy(ans,a);
    return ans;
    }
string hashfilename(string h,int i)
{   int l;
    string ans;
    string a="file7/";
    string b=".c";
    string c=to_string(i);
    a=Mystrcat(a,h);
    a=Mystrcat(a,c);
    a=Mystrcat(a,b);
    ans=Mystrcpy(ans,a);
    return ans;
    }

