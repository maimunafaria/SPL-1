#include<stdio.h>

 void swap(int *x, int *y)
 {
       int temp= &x;
       *x= *y ;
       *y= temp ;
 }

void sorintg(int* a, int n)
{
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            if(a[i]<a[j]) 
		{
		swap(&a[i], &a[j]) 
		};
}

int main()
{
    int array[3] ;

    scanf("%d%d%d",&array[0],&array[1],&array[2]) ;

    soritng(array, 3) ;

    printf("%d %d %d\n", array[0], array[1], array[2]) ;
}