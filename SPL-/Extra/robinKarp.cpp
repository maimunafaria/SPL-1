#include <iostream>
using namespace std;
#define d 256
void rabinKarp(string str, string subStr)
{
int n = str.length();
  int m = subStr.length();
  int p=0;
  int t=0;
  int h=1;
  int i,j;
  int countt=0;
  for(i=0;i<m-1;i++)
    {
        h=(h*d);
    }
  for(i=0;i<m;i++)
  {
    p=(d*p+subStr[i]);
    t=(d*t+str[i]);
  }
  for(i=0;i<=n-m;i++)
  {
    if(p==t)
    {
        int flag=0;
      for(j=0;j<m;j++)
      {
        if(str[i+j]!=subStr[j])
        {
            flag=1;
          break;
        }
      }
      if(flag==0)
      {
        countt++;
        cout<<"Similarity at: "<<i+1;
        cout<<"\n";
      }
    }
    if(i<n-m)
    {
      t=(d*(t-str[i]*h)+str[i+m]);
    }
  }
  cout<<"Similarity is found total "<<countt<<" times";
}
int main()
{
    string str;
    cin>>str;
    string subStr;
    cin>>subStr;
    rabinKarp(str,subStr);
    return 0;
}
