#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include <time.h>
#include <math.h>
#include <omp.h>

long long timer(void)
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (tv.tv_sec*1000000+tv.tv_usec);
}

void print_time(long long time)
{
	printf("%f\n",time/1000000.0);
}

int cnt =0 ;


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
    
   	  
   	x=count( S, m - 1, n ) ;
   	
	
	y= count( S, m, n-S[m-1] );
	
    

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
    long long time=timer();
    printf("%d \n", count(arr, coins, amount));
    
    
    print_time( timer() - time );
    return 0;
}
