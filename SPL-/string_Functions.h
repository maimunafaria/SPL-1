#include<cstring>
using namespace std;

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


char *stringToChar(string a)
{

    int n = Mystrlen(a);

    char char_array[n+1];

    strcpy(char_array, a.c_str());
    return (char *)char_array;}
