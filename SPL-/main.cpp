#include<iostream>
#include<fstream>
#include<stdlib.h>
#include <bits/stdc++.h>
#include <cstdlib>
#include"Tree.h"
#include"Calculation.h"
#include"edit_Distance.h"
#include"edit_Distance_New.h"
#include"SWM.h"



using namespace std;
string s1[5000];
int simple_tokenizer1(string s)
{
    stringstream ss(s);
    string word;
    int n=0;
    for(int i=0; ss >> word;i++) {
        s1[i]=word;
        n++;
    }
    return n;
}
int main()
{
    int i,j;
    ifstream my_file[20];
    string x[20];
    char ch;
    string fileName;
    cout<<"Enter the file name: ";
    cin>>fileName;
    cout<<"Which code clone detection technique you want to use?\n 1.SWM \n 2.Lexical Similarities \n 3.Tree\n";
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
    return 0;
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
    }
    return 0;
    }
    else if(number==3)
    {
        cout<<"By calculating the Number of common root of the trees\n";
        for(i=0;i<5;i++)
        {
                tree(hashfilename(fileName,i));
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=i+1;j<5;j++)
        {
                int a ,c;
                string y1[5000];
                string y2[5000];
                int num=0;
                a=simple_tokenizer1(treeString[i]);
                for(int u=0;u<a;u++)
                {
                    y1[u]=s1[u];
                }
                c=simple_tokenizer1(treeString[j]);
                for(int u=0;u<c;u++)
                {
                    y2[u]=s1[u];
                }
                if(a<c)
                {
                for(int u=0;u<a;u++)
                {
                    if(Mystrcmp(y1[u],y2[u])==0)
                    {

                        num++;
                    }
                }}
                else
                {
                for(int u=0;u<c;u++)
                {
                    if(Mystrcmp(y1[u],y2[u])==0)
                    {

                        num++;
                    }
                }
                }
                double percentage;
                percentage=(double(num)/((double(a)+(double(c)))/2))*100;
                cout<<"\t\t\t"<<" Code clone between of " <<i<< " and " <<j<<" = " <<percentage<< "%"<<"\t\t\n"<<endl;

        }
    }
}
