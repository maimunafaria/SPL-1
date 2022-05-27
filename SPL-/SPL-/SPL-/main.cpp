#include<iostream>
#include<fstream>
#include<stdlib.h>
#include"Calculation.h"
#include"edit_Distance.h"
#include"edit_Distance_New.h"
#include"SWM.h"


using namespace std;
int main()
{
    int i,j;
    ifstream my_file[20];
    string x[20];
    char ch;
    string fileName;
    cout<<"Enter the file name: ";
    cin>>fileName;
    cout<<"Which code clone detection technique you want to use?\n 1.SWM \n 2.Lexical Similarities \n 3.Parse tree\n";
    int number;
    cin>>number;
    if(number==1)
    {
        swm(fileName);
    for(i=0;i<5;i++)
    {
        for(j=i+1;j<5;j++)
        {

            if(numberOfCondition(i)==numberOfCondition(j) &&
               numberOfLoop(i)==numberOfLoop(j) &&
               numberOfVariable(i)==numberOfVariable(j)
               )
            {
                cout<<"Code clone percentage between file no " <<i << " and " <<j << " is very high\n" ;
            }
            else if(numberOfCondition(i)!=numberOfCondition(j) &&
               numberOfLoop(i)!=numberOfLoop(j) &&
               numberOfVariable(i)!=numberOfVariable(j)
               )
            {
                cout<<"Code clone percentage between file no " <<i << " and " <<j << " is very low\n" ;
            }
            else if(numberOfCondition(i)==numberOfCondition(j) && numberOfLoop(i)==numberOfLoop(j) &&
               numberOfVariable(i)!=numberOfVariable(j) || numberOfCondition(i)==numberOfCondition(j) &&
               numberOfLoop(i)!=numberOfLoop(j) && numberOfVariable(i)==numberOfVariable(j) ||
                numberOfCondition(i)!=numberOfCondition(j) && numberOfLoop(i)==numberOfLoop(j) &&
               numberOfVariable(i)!=numberOfVariable(j)
               )
               {
                   cout<<"Code clone percentage between file no " <<i << " and " <<j << " is high\n" ;
               }
            else
            {
                 cout<<"Code clone percentage between file no " <<i << " and " <<j << " is low\n" ;
            }


        }
    }
    }

    else if(number==2)
    {for(i=0;i<5;i++)
    {string input1,input2;
        my_file[i].open(input1=hashfilename(fileName,i), ios::in);
    while(!my_file[i].eof()){

   		ch = my_file[i].get();
   		x[i]+=ch;
	}//cout<<x[i]<<"\n"<<"\n";
	}
    for(i=0;i<5;i++)
    {
        for(j=i+1;j<5;j++)
        {
                int a ,c;

            a=Mystrlen(x[i]);
            c=Mystrlen(x[j]);
            int ed =editDistanceNew(x[i],x[j],a,c);
            calculation(i,j,a,c,ed);
        }
    }}
}
