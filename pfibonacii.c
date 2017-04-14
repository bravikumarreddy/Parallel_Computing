#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include <time.h>
#include <math.h>
#include <omp.h>
clock_t begin;

void starttimer(){
    begin = omp_get_wtime();
}

void endtimer(){
    clock_t end = omp_get_wtime();
    double elapsed = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nelapsed: %f\n",elapsed);
}

int fibo(int n){
	int i,j;
	if(n<2)
		return n;
	if (n < 30)
 return (fibo(n-1)+fibo(n-2)); 
	#pragma omp task shared(i)
	i=fibo(n-1);
	#pragma omp task shared(j)
	j=fibo(n-2);
	#pragma omp taskwait
	return i+j;
}
int main()
{
	int n ;
	scanf("%d",&n);
	int ans; 
	starttimer();
	#pragma omp parallel
	#pragma omp single
	ans= fibo(n);
	printf("\n %d \n",ans);
	
	endtimer();
	
}

