#include<iostream>
#include<fstream>
#include<stdlib.h>
#include"Calculation.h"
#include"edit_Distance.h"
#include"output_File.h"
#include"lexical_Analysis.h"


using namespace std;
int main()
{
    outputFileCreate();
    lexicalAnalysis();
    int i,j;
    ifstream my_file[20];
    string x[20];
    char ch;
    for(i=0;i<5;i++)
    {string input1,input2;
        my_file[i].open(input1=hashfilename(i), ios::in);
    while(!my_file[i].eof()){

   		ch = my_file[i].get();
   		x[i]+=ch;
	}//cout<<x[i]<<"\n"<<"\n";
	}
    for(i=0;i<5;i++)
    {
        for(j=i;j<5;j++)
        {
                int a ,c;

            a=Mystrlen(x[i]);
            c=Mystrlen(x[j]);
            int ed =editDistance(x[i],x[j],a,c);
            calculation(i,j,a,c,ed);
        }
    }

}
