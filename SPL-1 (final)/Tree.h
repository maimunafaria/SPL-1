#include <iostream>
#include <bits/stdc++.h>
#include<fstream>
#include <cstdlib>
using namespace std;
string strings[5000];
string treeString[20];
int st=0;

//OP OP KW ID ID ID ID ID ID ID ID ID ID ID ID ID ID ID ID ID ID ID ID ID CN ID ID ID ID ID ID ID ID ID ID ID ID ID KW KW KW KW KW KW KW KW KW KW OP OP OP OP OP OP OP OP OP OP LP LP OP NM NM NM NM OP OP OP OP OP OP OP OP OP OP OP//
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
    int index=0,i=0,stri=0, endi=0,n=0;

    while (i<=Mystrlen1(str))
    {
        if (str[i]==sep || i==Mystrlen1(str))
        {
            endi=i;
            string subStr="";
            subStr.append(str, stri, endi - stri);
            strings[index]=subStr;
            index=index+1;
            stri=endi+1;
        }
        i++;

        }
     return index;
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

struct Node
 {
	string data;
	Node* left;
	Node* right;
};
Node* root ;
class Binary_tree
 {
public:
    Binary_tree();
    Node*  Newnode(string );
    Node* Insert(Node* ,string );
    void pre(Node*);

};
Binary_tree::Binary_tree()
{
    root = NULL;
}

Node* Binary_tree:: Newnode(string data)
{
	Node* newNode = new Node();
	(*newNode).data = data;
	(*newNode).left = NULL;
	(*newNode).right = NULL;
	return newNode;
}

Node* Binary_tree::Insert(Node* root,string data)
{
	if(root == NULL)
        {
		root = Newnode(data);
	}
	else if(data <= (*root).data)
	{
		(*root).left = Insert((*root).left,data);
	}
	else
	 {
		(*root).right = Insert((*root).right,data);
	}
	return root;
}
void Binary_tree:: pre(Node* t = root)
{
    if (t!=NULL)
        {
    //    cout<<(*t).data<<" ";
        treeString[st]+=(*t).data;
        treeString[st]+=" ";
        pre((*t).left);
        pre((*t).right);

    }
}

void tree(string name)
{
        Binary_tree b;
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

                root=b.Insert(root ,strings[k]);
            }
            }
         //  cout << "\n\nThe tree of file  " << input1 <<"\n\n";
            b.pre();
         /* cout << "\n\nThe tree of files" <<"\n\n";
           cout<<treeString[2];
           cout<<"\n";
           cout<<treeString[5];*/
            st++;

}

