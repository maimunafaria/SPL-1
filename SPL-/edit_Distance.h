#ifndef EDIT_DISTANCE_H_INCLUDED
#define EDIT_DISTANCE_H_INCLUDED



#endif // EDIT_DISTANCE_H_INCLUDED
using namespace std;
int editDistance(string x , string y , int m , int n)
{
    int i,j;
  //here the string x and y are the c files and m,n are the string length of the string x,y
  //the two-d array to find string similarities
    int c[m+1][n+1];

     for (i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0)
            {
                c[i][j]=j;
            }
            else if(j==0)
            {
                c[i][j]=i;
            }
            else if (x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1];
            }
             else
                {if(c[i-1][j-1]<=c[i-1][j] && c[i-1][j-1]<=c[i][j-1])
                 {c[i][j]=1+c[i-1][j-1];
                 }

                 else if(c[i-1][j]<=c[i-1][j-1] && c[i-1][j]<=c[i][j-1])
                 {c[i][j]=1+c[i-1][j];
                 }
                 else if(c[i][j-1]<=c[i-1][j] && c[i][j-1]<=c[i-1][j-1])
                 {c[i][j]=1+c[i][j-1];
                 }}

        }
    }
    return c[m][n];
}
