#include<stdio.h>

 void swap(int *a, int *b)
 {
       int temp= &a;
       *a= *b ;
       *b= temp ;
 }

void b_sort(int* a, int n)
{
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            if(a[i]<a[j]) swap(&a[i], &a[j]) ;
}

int main()
{
    int ar[3] ;

    	scanf("%d",&ar[0]) ;
	scanf("%d",&ar[1]) ;
	scanf("%d",&ar[2]) ;

    b_sort(ar, 3) ;

    printf("%d %d %d\n", ar[0], ar[1], ar[2]) ;
}