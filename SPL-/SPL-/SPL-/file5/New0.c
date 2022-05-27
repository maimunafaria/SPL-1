#include<stdio.h>
#include<math.h>
#define m 2

int main()
{
    int c=0,n,i,j,l,k,f,x,g=2, count=0;;
    char s,t;

    printf("Enter the total state number\n");
    scanf("%d" , &n);
    printf("Enter the states:\n");
    char states[n];// The states
    for(i=0;i<n;i++)
    {
        scanf("\n%c" , &states[i]);
    }

    printf("The states are:\n");
    for(i=0;i<n;i++)
    {
        printf("%c  " , states[i]);
    }
    printf("\nThe alphabets are:\n0 and 1");
    printf("\nEnter the starting state \n");
    scanf("\n%c" , &s);
    printf("Starting state is %c \n" , s);
    printf("Enter the number of final states:\n");
    scanf("%d" , &f);
    char fstates[f];
    printf("Enter the final states: \n");
    for(i=0;i<f;i++)
    {
        scanf("\n%c" , &fstates[i]);
    }
    printf("Final state :"  );

    for(i=0;i<f;i++)
    {
        printf("\n%c" , fstates[i]);
    }
    char transitiontable[n+1][m+1][n];

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            for(k=0;k<n;k++)
            {transitiontable[i][j][k]=' ';}//iniitialization of the nfa table
        }
    }

            transitiontable[0][1][0]='0';//storing the alphabets in the table (index i is 0)
            transitiontable[0][2][0]='1';

        j=0;
        for(i=1;i<=n;i++)
        {
            transitiontable[i][0][0]=states[j];//storing the states in the table
            j++;
        }
        printf("\nEnter the Transition table of the nfa:\n");
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {int b=0;
             printf("To go from %c by %c(to break press #): ", transitiontable[i][0][0],transitiontable[0][j][0]);
            for(k=0;k<n;k++)
            {

                scanf("\n%c" , &transitiontable[i][j][k]);
                b++;
                if(transitiontable[i][j][k]=='#')//if anyone press # then it will stop taking inputs
                {
                    if(b==1)
                    {
                        break; //if the only input is #
                    }
                    else if (b>1)
                    {
                    transitiontable[i][j][k]=' ';// if one or two inputs are taken earlier
                    break;
                    }
                }
            }
            }
        }
    printf("\n\nThe transition table(nfa):\n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
         for(k=0;k<n;k++)
        {
            printf("%c " ,transitiontable[i][j][k]); // printing the nfa table
        }
        }
        printf("\n");
    }
    x=pow(2,n);
    char dfaTransitionTable[100][m+1][n];

     for(i=0;i<100;i++)
    {
        for(j=0;j<=m;j++)
        {
            for(k=0;k<n;k++)
            {dfaTransitionTable[i][j][k]=' ';} //initialization of the dfa table
        }
    }

            dfaTransitionTable[0][1][0]='0';// storing the alphabets
            dfaTransitionTable[0][2][0]='1';


    printf("\nThe transition table(dfa):\n");

    for(i=0;i<=n;i++)
    {
        if(transitiontable[i][0][0]==s){
        for(j=0;j<=m;j++)
        {
            for(k=0;k<n;k++)
            {

                dfaTransitionTable[1][j][k]=transitiontable[i][j][k]; // storing the 1st state of the dfa which is the staring state of the nfa
            }
        }}
    }
    int u;
    for(i=1;i<=x;i++)
    {
        for(j=1;j<=m;j++)
        {
            for(k=0;k<n;k++)
            {//Storing the states that are being created after the staring state of the nfa is placed in the dfa table
                dfaTransitionTable[g][0][k]=dfaTransitionTable[i][j][k];
                for(u=1;u<=n;u++)
                {
                    if(dfaTransitionTable[g][0][k]==transitiontable[u][0][0])//if its equal to a state of the nfa table we have to store all the states
                                                                            // that can be reached from that nfa state
                    {
                        for(int z=1;z<=m;z++)
                            {
                                for(int y=0;y<n;y++)
                                    {
                                        if(dfaTransitionTable[g][z][y]==' ' && transitiontable[u][z][y]!=' '  &&transitiontable[u][z][y]!='#')
                                        { //if the dfa cell is empty of, nfa cell is not empty and nfa cell is not = # then store
                                                   {
                                                    dfaTransitionTable[g][z][y]=transitiontable[u][z][y];
                                                   }
                                        }
                                        else if( transitiontable[u][z][y]==' '){}

                                        else//if the new state is combination of two or more states of the nfa then we will store the reached state
                                            // of the 2nd or 3rd state(from the combination) then we will check if it is # or the same one
                                            // that are reached from the previous state (from the combination)
                                            //if not then store
                                        {
                                            char v = transitiontable[u][z][y];
                                            {
                                               for(int r=0;r<n;r++)
                                               {
                                                    if(dfaTransitionTable[g][z][r]==v || v=='#')
                                                    {
                                                        v=' ';
                                                    }
                                               }

                                            }
                                         //   printf("%c" ,v);
                                            for(int r=0;r<n;r++)
                                            {
                                            if(dfaTransitionTable[g][z][r]==' ')
                                                    {
                                                    dfaTransitionTable[g][z][r]=v;
                                                    break;
                                                    }

                                            }

                                        }

                                    }
                            }
                    }
                }
            }g++;}}

        printf("\n");
// sorting the dfa table to be able to delete states (ba ,ab )
    for(k=0;k<=g;k++)
    {
        for(int q=0;q<=m;q++)
        {

    for(i=0; i<n; i++)
	{
		for(j=i; j<n;j++)
		{

			if (dfaTransitionTable[k][q][i] <= dfaTransitionTable[k][q][j])
			{
				char arrtemp;
				arrtemp = dfaTransitionTable[k][q][i];
				dfaTransitionTable[k][q][i] =dfaTransitionTable[k][q][j];
				dfaTransitionTable[k][q][j] = arrtemp;
			}
		}
	}
 }
    }
// deleting same states
 for(i=0;i<=g;i++)
 for(int h=i+1;h<=g;h++){
 {int same=0;
        for(j=0;j<=m;j++)
     {
         for(k=0;k<n;k++)
         {
             if(dfaTransitionTable[i][j][k]==dfaTransitionTable[h][j][k])
             {
                 same++;

             }
         }
     }if(same==n*(m+1))
     {
         for(j=0;j<=m;j++)
         {
        for(k=0;k<n;k++)
       {dfaTransitionTable[h][j][k]=' ';}}
     }

 }}
    int count3=0;
    for(i=0;i<=g+1;i++)
    {
        if(i>0 && dfaTransitionTable[i][0][0]==' ')
        {
         ;
        }
        else
        {for(j=0;j<=m;j++)
        {
         for(k=0;k<n;k++)
        {
            if(i>0 && dfaTransitionTable[i][j][0]==' ')
            {
                dfaTransitionTable[i][j][0]='#';
            }
          printf("%c " ,dfaTransitionTable[i][j][k]);
        }
        }
        printf("\n");
        }
    }
    printf("\nThe Final States: \n");


        char finalState[100][n];
        int z=0;
        int count2=0;
        for(i=1;i<=g;i++)
        {
            count2=0;
            for(k=0;k<n;k++)
            {
                for(l=0;l<f;l++)
                {
                    if(dfaTransitionTable[i][0][k]==fstates[l])//if the dfa states match with the final states of the nfa
                    {
                        count2++;
                    }
                    if(count2>0)
                    {
                        for(z,k=0;z<=x,k<n;k++)
                        {

                            finalState[z][k]=dfaTransitionTable[i][0][k];// then we will store it as a final state of the dfa

                        }z++;
                    }
                }
            }}
    for(i=0;i<z;i++)
    {
            for(j=0;j<n;j++)

            {printf("%c " , finalState[i][j]);}
            printf("\n");
    }
 //   printf("The death state :\n#  #  #  ");


    return 0;
}
