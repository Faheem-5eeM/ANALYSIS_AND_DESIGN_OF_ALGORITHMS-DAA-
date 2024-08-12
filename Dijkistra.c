#include <stdio.h>
#define INF 9999
#define MAX 10
void DijkstraAlgorithm(int Graph[MAX][MAX], int size, int start)
{
    int cost[MAX][MAX], distance[MAX], previous[MAX];
    int visited_nodes[MAX], counter, minimum_distance, next_node, i, j;
    for (i = 0; i < size; i++)
    for (j = 0; j < size; j++)
    if (Graph[i][j] == 0)
       cost[i][j] = INF;
    else
       cost[i][j] = Graph[i][j];
    for (i = 0; i < size; i++)
    {
        distance[i] = cost[start][i];
        previous[i] = start;
        visited_nodes[i] = 0;
    }
    distance[start] = 0;
    visited_nodes[start] = 1;
    counter = 1;
    while (counter < size - 1)
    {
        minimum_distance = INF;
        for (i = 0; i < size; i++)
        if (distance[i] < minimum_distance && !visited_nodes[i])
        {
            minimum_distance = distance[i];
            next_node = i;
        }
        visited_nodes[next_node] = 1;
        for (i = 0; i < size; i++)
        if (!visited_nodes[i])
          if (minimum_distance + cost[next_node][i] < distance[i])
          {
              distance[i] = minimum_distance + cost[next_node][i];
              previous[i] = next_node;
          }
          counter++;
    }
    for (i = 0; i < size; i++)
    if (i != start)
    {
       printf("\nDistance from the Source Node to %d: %d", i, distance[i]);
    }
}
void main()
{
    int Graph[MAX][MAX], i, j, n, source;
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    printf("Enter the cost adjacency Matrix:\n");
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
         scanf("%d",&Graph[i][j]);
      }
    }
    source = 0;
    DijkstraAlgorithm(Graph, n, source);
}