#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include <time.h>
#include <math.h>
#include <omp.h>
int cnt =0 ;

clock_t begin;

void starttimer(){
    begin = omp_get_wtime();
}

void endtimer(){
    clock_t end = omp_get_wtime();
    double elapsed = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nelapsed: %f\n seconds",elapsed);
}

int count( int S[], int m, int	 n )
{
    
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (m <=0 && n >= 1)
        return 0;
        int x;
        int y;
    if(n<125)
    	return count( S, m - 1, n ) + count( S, m, n-S[m-1] );
   	#pragma omp task shared(x)
   	{  
   	x=count( S, m - 1, n ) ;
   	}
	#pragma omp task  shared(y)  
	{
	y= count( S, m, n-S[m-1] );
	}
    

#pragma omp taskwait
return x+y;

}
 
int main()
{
    int amount,coins;
    scanf("%d",&amount);
    scanf("%d",&coins);
    int *arr = malloc(sizeof(int)*coins);
    
    for(int i=0;i<coins;i++){
    		scanf("%d",&arr[i]);
    }
    
    int m = sizeof(arr)/sizeof(arr[0]);
    starttimer();
    #pragma omp parallel
    #pragma omp single
    printf("%d ", count(arr, coins, amount));
    endtimer();
    return 0;
}
