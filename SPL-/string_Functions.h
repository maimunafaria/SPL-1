#ifndef STRING_FUNCTIONS_H_INCLUDED
#define STRING_FUNCTIONS_H_INCLUDED



#endif // STRING_FUNCTIONS_H_INCLUDED
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
