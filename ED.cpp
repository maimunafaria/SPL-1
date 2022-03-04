#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;
int Mystrlen(string a)
{
    int i,length=0;
    for(i=0;a[i]!='\0';i++)
    {
        length++;
    }
    return length;
}
string Mystrcpy(string a ,string b)
{
    a=b;
    return a;
}
string Mystrcat(string a ,string b)
{
    a=a+b;
    return a;
}
string hashfilename(int i)
{   int l;
    string ans;
    string a="D:/New folder (2)/file7/New";
    string b=".c";
    string c=to_string(i);
    a=Mystrcat(a,c);
    a=Mystrcat(a,b);
    ans=Mystrcpy(ans,a);
    return ans;
    }
int editDistance(string x , string y , int m , int n)
{
    int i,j;
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
int main()
{
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
        int ed = editDistance(x[i],x[j],a,c);
       // cout<<"Number of edit distance between "<< i << " and " << j << " is " <<ed<<endl;
        int maxlength;
        if (a>=c)
        {
            maxlength=a;
        }
        else
        {
            maxlength=c;
        }
        double percentage;
        percentage=(double(maxlength)-double(ed))/double(maxlength)*100;
      //  cout<<"percentage of code clone between " <<i << " and " << j << " is " <<percentage<< "%"<<endl;
        cout<<"\t\t\t"<<" Percentage of code clone between "<<"\t\t"<<endl;
        cout<<"\t\t\t"<<"    File No: "<<i<< " and " << "File No: "<<j<<"\t\t"<<endl;
        cout<<"\t\t\t\t"<< " is " <<percentage<< "%"<<"\t\t\n"<<endl;

}
}
}
