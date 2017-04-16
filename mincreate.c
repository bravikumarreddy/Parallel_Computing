#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include <time.h>
#include <math.h>
#include <omp.h>

clock_t start, end;
double cpu_time_used;



void starttimer(){
    start = clock();
}

void endtimer(){
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nelapsed: %f\n seconds",cpu_time_used);
}

int main(){
	long long number;
	//printf("Enter the total number of elements\n");
	
	scanf("%lld",&number);
	//printf("Enter the elements \n");
	
	long long *arr;
	
	arr = malloc(sizeof(long long)*number);
  
	for(int i=0;i<number;i++){
		scanf("%lld",&arr[i]);
	}
	int nthrds = omp_get_max_threads();
	long long max = arr[0];
	starttimer();
	int x =0;
	#pragma omp parallel
	{
		long long local_max = max;
		
		#pragma omp for nowait
		for(int i=1; i<number; i++){
		
			long long local_result;
			/* Parrallel computation goes here */
			/* Assumaxg that local_result will get the value after computation */
			local_result = arr[i];
		
			if( local_result > local_max  ){
					local_max = local_result;
			}
		}
		
		#pragma omp critical
		{
			if( local_max > max  ){
			
				max = local_max;
			
			}
		}
	
	}
	
	endtimer();
	printf(" result \n %lld \n  %d " ,max ,x );
	free(arr);
	
	
	
	
}
