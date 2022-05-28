#include<iostream>
#include"output_File.h"
#include"lexical_Analysis.h"
#include<vector>
#include<algorithm>
#include"pattern_Match.h"



using namespace std;
void remove(vector<string> &x)
{
    auto end = x.end();
    for (auto i = x.begin(); i != end; ++i) {
        end = remove(i + 1, end, *i);
    }

    x.erase(end, x.end());
}
void swm(string fileName)
{
    outputFileCreate(fileName);
   lexicalAnalysis(fileName);
    int i;
    int n=0;
    ifstream my_file[20];
    string x[20];
    for(i=0;i<5;i++)
    {string input1;
         my_file[i].open(input1=hashfilename(fileName,i), ios::in);
         if (!my_file[i]) {
		cout << "File not created";
		n++;
		break;
		}
        cout<<"No of Loop in file no "<<i<<" is "<<numberOfLoop(i)<<"\t";
       cout<<"No of condition in file no "<<i<<" is "<<numberOfCondition(i)<<"\t";
        char ch;
        while(!my_file[i].eof()){
        ch = my_file[i].get();
   		x[i]+=ch;}
   		string substring="_KW_ID_PB";
        int functionNumber =rabinKarp(x[i],substring);
        cout<<"No of functions in file no "<<i<<" is "<<functionNumber<<"\t";
        remove(variable[i]);
        cout<<"No of Variable in file no "<<i<<" is "<<numberOfVariable(i)-functionNumber<<"\t";
        cout<<"\n";

    }if(n==0)
    {for(i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
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
    }}
}
