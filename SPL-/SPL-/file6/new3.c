#include<stdio.h>#include<math.h>#define m 2int main(){    int c=0,n,i,j,l,k,f,x,g=2, count=0;;    char s,t;    printf("Enter the total state number\n");    scanf("%d" , &n);    printf("Enter the states:\n");    char states[n];    for(i=0;i<n;i++)    {        scanf("\n%c" , &states[i]);    }    printf("The states are:\n");    for(i=0;i<n;i++)    {        printf("%c  " , states[i]);    }    printf("\nThe alphabets are:\n0 and 1");    printf("\nEnter the starting state \n");    scanf("\n%c" , &s);    printf("Starting state is %c \n" , s);    printf("Enter the number of final states:\n");    scanf("%d" , &f);    char fstates[f];    printf("Enter the final states: \n");    for(i=0;i<f;i++)    {        scanf("\n%c" , &fstates[i]);    }    printf("Final state :"  );    for(i=0;i<f;i++)    {        printf("\n%c" , fstates[i]);    }    char transitiontable1[n+1][m+1][n];    for(i=0;i<=n;i++)    {        for(j=0;j<=m;j++)        {            for(k=0;k<n;k++)            {transitiontable1[i][j][k]=' ';}        }    }            transitiontable1[0][1][0]='0';            transitiontable1[0][2][0]='1';        j=0;        for(i=1;i<=n;i++)        {            transitiontable1[i][0][0]=states[j];            j++;        }        printf("\nEnter the Transition table of the nfa:\n");        for(i=1;i<=n;i++)        {            for(j=1;j<=m;j++)            {int b=0;             printf("To go from %c by %c(to break press #): ", transitiontable1[i][0][0],transitiontable1[0][j][0]);            for(k=0;k<n;k++)            {                scanf("\n%c" , &transitiontable1[i][j][k]);                b++;                if(transitiontable1[i][j][k]=='#')                {                    if(b==1)                    {                        break;                     }                    else if (b>1)                    {                    transitiontable1[i][j][k]=' ';                    break;                    }                }            }            }        }    printf("\n\nThe transition table(nfa):\n");    for(i=0;i<=n;i++)    {        for(j=0;j<=m;j++)        {         for(k=0;k<n;k++)        {            printf("%c " ,transitiontable1[i][j][k]);         }        }        printf("\n");    }    x=pow(2,n);    char dfatransitiontable1[100][m+1][n];     for(i=0;i<100;i++)    {        for(j=0;j<=m;j++)        {            for(k=0;k<n;k++)            {dfatransitiontable1[i][j][k]=' ';}         }    }            dfatransitiontable1[0][1][0]='0';            dfatransitiontable1[0][2][0]='1';    printf("\nThe transition table(dfa):\n");    for(i=0;i<=n;i++)    {        if(transitiontable1[i][0][0]==s){        for(j=0;j<=m;j++)        {            for(k=0;k<n;k++)            {                dfatransitiontable1[1][j][k]=transitiontable1[i][j][k];             }        }}    }    int u;    for(i=1;i<=x;i++)    {        for(j=1;j<=m;j++)        {            for(k=0;k<n;k++)            {                dfatransitiontable1[g][0][k]=dfatransitiontable1[i][j][k];                for(u=1;u<=n;u++)                {                    if(dfatransitiontable1[g][0][k]==transitiontable1[u][0][0])                                                                                                {                        for(int z=1;z<=m;z++)                            {                                for(int y=0;y<n;y++)                                    {                                        if(dfatransitiontable1[g][z][y]==' ' && transitiontable1[u][z][y]!=' '  &&transitiontable1[u][z][y]!='#')                                        {                                                    {                                                    dfatransitiontable1[g][z][y]=transitiontable1[u][z][y];                                                   }                                        }                                        else if( transitiontable1[u][z][y]==' '){}                                        else                                                                                                                                                                            {                                            char v = transitiontable1[u][z][y];                                            {                                               for(int r=0;r<n;r++)                                               {                                                    if(dfatransitiontable1[g][z][r]==v || v=='#')                                                    {                                                        v=' ';                                                    }                                               }                                            }                                                                                     for(int r=0;r<n;r++)                                            {                                            if(dfatransitiontable1[g][z][r]==' ')                                                    {                                                    dfatransitiontable1[g][z][r]=v;                                                    break;                                                    }                                            }                                        }                                    }                            }                    }                }            }g++;}}        printf("\n");    for(k=0;k<=g;k++)    {        for(int q=0;q<=m;q++)        {    for(i=0; i<n; i++){for(j=i; j<n;j++){if (dfatransitiontable1[k][q][i] <= dfatransitiontable1[k][q][j]){char arrtemp;arrtemp = dfatransitiontable1[k][q][i];dfatransitiontable1[k][q][i] =dfatransitiontable1[k][q][j];dfatransitiontable1[k][q][j] = arrtemp;}}} }    } for(i=0;i<=g;i++) for(int h=i+1;h<=g;h++){ {int same=0;        for(j=0;j<=m;j++)     {         for(k=0;k<n;k++)         {             if(dfatransitiontable1[i][j][k]==dfatransitiontable1[h][j][k])             {                 same++;             }         }     }if(same==n*(m+1))     {         for(j=0;j<=m;j++)         {        for(k=0;k<n;k++)       {dfatransitiontable1[h][j][k]=' ';}}     } }}    int count3=0;    for(i=0;i<=g+1;i++)    {        if(i>0 && dfatransitiontable1[i][0][0]==' ')        {         ;        }        else        {for(j=0;j<=m;j++)        {         for(k=0;k<n;k++)        {            if(i>0 && dfatransitiontable1[i][j][0]==' ')            {                dfatransitiontable1[i][j][0]='#';            }          printf("%c " ,dfatransitiontable1[i][j][k]);        }        }        printf("\n");        }    }    printf("\nThe Final States: \n");        char finalState[100][n];        int z=0;        int count2=0;        for(i=1;i<=g;i++)        {            count2=0;            for(k=0;k<n;k++)            {                for(l=0;l<f;l++)                {                    if(dfatransitiontable1[i][0][k]==fstates[l])                    {                        count2++;                    }                    if(count2>0)                    {                        for(z,k=0;z<=x,k<n;k++)                        {                            finalState[z][k]=dfatransitiontable1[i][0][k];                        }z++;                    }                }            }}    for(i=0;i<z;i++)    {            for(j=0;j<n;j++)            {printf("%c " , finalState[i][j]);}            printf("\n");    }     return 0;}