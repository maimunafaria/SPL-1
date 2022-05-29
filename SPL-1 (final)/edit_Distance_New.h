using namespace std;
int editDistanceNew(string x, string y,int m,int n)
{
    int c[2][m + 1];
        for(int i=0;i<=m;i++)
        {
            c[0][i]=i;
        }
    for (int i=1;i<=n;i++)
        {
            for (int j=0;j<=m;j++)
                {

                if(j==0)
                    {
                        c[i%2][j]=i;
                    }

                else if(x[j-1]==y[i-1])
                    {
                        c[i%2][j]=c[(i-1)%2][j-1];
                    }


                else
                    /*{
                    c[i% 2][j] = 1 + min(c[(i - 1) % 2][j],
                                           min(c[i % 2][j - 1],
                                               c[(i - 1) % 2][j - 1]));
                    }*/
                    {if(c[(i-1)%2][j-1]<=c[(i-1)%2][j] && c[(i-1)%2][j-1]<=c[i%2][j-1])
                 {c[i%2][j]=1+c[(i-1)%2][j-1];
                 }

                 else if(c[(i-1)%2][j]<=c[(i-1)%2][j-1] && c[(i-1)%2][j]<=c[i%2][j-1])
                 {c[i%2][j]=1+c[(i-1)%2][j];
                 }
                 else if(c[i%2][j-1]<=c[(i-1)%2][j] && c[i%2][j-1]<=c[(i-1)%2][j-1])
                 {c[i%2][j]=1+c[i%2][j-1];
                 }}
        }
    }


    return c[n%2][m];
}
