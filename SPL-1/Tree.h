#include <iostream>
#include <bits/stdc++.h>
#include<fstream>
#include <cstdlib>
using namespace std;
string strings[5000];
string treeString[20];
int st=0;


int Mystrlen1(string a)
{
    int i,length=0;
    for(i=0;a[i]!='\0';i++)
    {
        length++;
    }
    return length;
}

int split (string str, char sep)
{
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    int n=0;
    while (i <= Mystrlen1(str))
    {
        if (str[i] == sep || i == Mystrlen1(str))
        {
            endIndex = i;
            string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            strings[currIndex] = subStr;
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;

        }
     return currIndex;
}

int Mystrcmp1(string a , string b)
{
    int x = a.compare(b);
    if (x != 0)
    {
        return 1;
    }
    else
        {
            return 0;
        }
}

struct tree {
    string info;
    tree *Left, *Right;
};
tree* root;
class Binary_tree {
public:
    Binary_tree();
    void insert1(string);
    tree* insert2(tree*, tree*);
    void pretrav(tree* );

};
Binary_tree::Binary_tree()
{
    root = NULL;
}
tree* Binary_tree::insert2(tree* temp, tree* newnode)
{
    if (temp == NULL) {
        temp = newnode;
    }
    else if (temp->info < newnode->info) {
        insert2(temp->Right, newnode);
        if (temp->Right == NULL)
            temp->Right = newnode;
    }
    else {
        insert2(temp->Left, newnode);
        if (temp->Left == NULL)
            temp->Left = newnode;
    }
    return temp;
}
void Binary_tree::insert1(string n)
{
    tree *temp = root, *newnode;
    newnode = new tree;
    newnode->Left = NULL;
    newnode->Right = NULL;
    newnode->info = n;
  //  cout<<n;
    root = insert2(temp, newnode);
}
void Binary_tree::pretrav(tree* t = root)
{
    if (root == NULL) {
        cout << "Nothing to display";
    }
    else if (t != NULL) {
     //  cout << t->info << " ";
        treeString[st]+=t->info;
        treeString[st]+=" ";
        pretrav(t->Left);
        pretrav(t->Right);

    }
}

void tree(string name)
{
    Binary_tree bt;


        string x;
        char ch;
        int stringNo;
        string input1;
        ifstream my_file;
        my_file.open(input1=name, ios::in);
        while(!my_file.eof()){

   		ch = my_file.get();
   		x+=ch;

        }
        char seperator = '_';
        stringNo=split(x,seperator);
        //cout<<x[i]<<"\n"<<"\n";
            for(int k=0;k<stringNo;k++)
            {
            if(Mystrcmp1(strings[k],"OP")==0 || Mystrcmp1(strings[k],"NM")==0 ||Mystrcmp1(strings[k],"KW")==0 || Mystrcmp1(strings[k],"CN")==0
                  || Mystrcmp1(strings[k],"LP")==0 || Mystrcmp1(strings[k],"ID")==0)
            {

                bt.insert1(strings[k]);
            }
            }
           // cout << "\n\nThe tree of file  " << input1 <<"\n\n";
            bt.pretrav();
          // cout << "\n\nThe tree of files" <<"\n\n";
           //cout<<treeString[st];
            st++;

}
