// A C / C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
  
#include <stdio.h>
#include <limits.h>
#include<stdlib.h>
#include <sys/time.h>
#include<omp.h>
// Number of vertices in the graph

  
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
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
  
   for (int v = 0; v < k; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
  
// A utility function to print the constructed distance array
int printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < n; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}
  
// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int **graph, int src,int v)
{
     int *dist = (int *)malloc(v*sizeof(int));     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
  
     bool *sptSet =  (bool *)malloc(v*sizeof(bool));
  
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < v; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
  
     // Find shortest path for all vertices
     for (int count = 0; count < v-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet,v);
  
       // Mark the picked vertex as processed
       sptSet[u] = true;
  
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int k = 0; k < v; k++)
  
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[k] && graph[u][k] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][k] < dist[k])
            dist[k] = dist[u] + graph[u][k];
     }
  
     // print the constructed distance array
     //printSolution(dist, v);
     
     free(dist);
     free(sptSet);
}
  
// driver program to test above function
int main()
{
   /* Let us create the example graph discussed above */
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

