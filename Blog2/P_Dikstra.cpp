 #include <stdio.h>
#include <limits.h>
#include<stdlib.h>
#include <sys/time.h>
#include<omp.h>

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

int minDistance(int dist[], bool sptSet[],int k)
{
   
   int min = INT_MAX, min_index;
   if(k>100){
  #pragma omp parallel
  {
  	int loc_min = INT_MAX;
  	int loc_index;
  	
  #pragma omp  for 	nowait
   for (int v = 0; v < k; v++)
     if (sptSet[v] == false && dist[v] <= loc_min)
         loc_min = dist[v], loc_index = v;
  
  	
		if( loc_min < min  ){
			
			#pragma omp critical
			{
				if( loc_min < min  ){
				
				min = loc_min;
				min_index = loc_index;
				
				}
			}
			}
   	
	
  }
  
  }
  else{
  
  	for (int v = 0; v < k; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
  }
   return min_index;
}
  

int printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < n; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}
  
void dijkstra(int **graph, int src,int v)
{
     int *dist = (int *)malloc(v*sizeof(int));     
  
     bool *sptSet =  (bool *)malloc(v*sizeof(bool));
  
      #pragma omp parallel for
     for (int i = 0; i < v; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
     dist[src] = 0;
  
     
     for (int count = 0; count < v-1; count++)
     {
       int u = minDistance(dist, sptSet,v);
  
       sptSet[u] = true;
  
       for (int k = 0; k < v; k++)
  
         
         if (!sptSet[k] && graph[u][k] && dist[u] != INT_MAX && dist[u] + graph[u][k] < dist[k])
            dist[k] = dist[u] + graph[u][k];
     }
  
     //printSolution(dist, v);
     
     free(dist);
     free(sptSet);
}
  
int main()
{
   int v;
   scanf("%d",&v);
   int** graph;
   graph = (int **)malloc(v*sizeof(int *));
   for(int i=0;i<v;i++){
   		graph[i] = (int *)malloc( v*sizeof(int));
   }
   for(int i=0;i<v;i++){
   	for(int j=0;j<v;j++){
   		scanf("%d",&graph[i][j]);
   	}
   }  
 long long time = timer();
 
    dijkstra(graph, 0,v);
    
  print_time(timer()-time);
  
  for(int i=0;i<v;i++){
  
   		free(graph[i]);
  }
   
   free(graph);
    return 0;
}

