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
    ifstream my_file[20];
    string x[20];
    for(i=0;i<5;i++)
    {string input1;
         my_file[i].open(input1=hashfilename(fileName,i), ios::in);
         if (!my_file[i]) {
		cout << "File not created";
		break;}
        cout<<"No of Loop in file no "<<i<<" is "<<numberOfLoop(i)<<"\t";
        cout<<"No of condition in file no "<<i<<" is "<<numberOfCondition(i)<<"\t";
        char ch;
        while(!my_file[i].eof()){
        ch = my_file[i].get();
   		x[i]+=ch;}
   		string substring="_KW _ID_ PB ";
        int functionNumber =rabinKarp(x[i],substring);
        cout<<"No of functions in file no "<<i<<" is "<<functionNumber<<"\t";
        remove(variable[i]);
        cout<<"No of Variable in file no "<<i<<" is "<<numberOfVariable(i)-functionNumber<<"\t";
        cout<<"\n";

    }
}
