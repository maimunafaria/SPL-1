#include<stdio.h>

int ans(int a)
{return a;}

int main()
{

	int a;
	scanf("%d" , a);
	for(int i=0;i<a;i++)
	{ int sum =0;
		sum+=a;
		ans(sum);
	}
}