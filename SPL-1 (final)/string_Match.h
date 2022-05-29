#include <iostream>
using namespace std;

int KMP(string t, string p)
{
    int i,j,m=0,n=0;
    for(i=0;t[i]!='\0';i++)
    {
        m++;
    }
    for(i=0;p[i]!='\0';i++)
    {
        n++;
    }
    int match=0;


    if(n==0 || m<n)
    {
        return 0;
    }
    int arrays[n + 1];

    for(i=0;i<n+1;i++)
        {
        arrays[i]=0;
        }

    for(i=1;i<n;i++)
    {
        j=arrays[i+1];

        while(j>0 && p[j]!=p[i])
        {
            j=arrays[j];
        }

        if (j>0 || p[j]==p[i])
        {
            arrays[i+1] = j+1;
        }
    }

    for(i=0,j=0;i<m;i++)
    {
        if(t[i]==p[j])
        {
            if(++j==n)
            {
                match++;
            }
        }
        else if (j>0)
        {
            j=arrays[j];
            i--;
        }
    }
    return match;
}
