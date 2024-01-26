//************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 5
//        Date: 10/8/2023
// Description: Program will implement Dijkstra's shortest path algorithm using a priority queue. Given a  
//              graph and a source vertex in the graph, the program will determine the shortest path using 
//              adjacency matrix representation. 
//************************************************************************************************************

#include <iostream>
#include <limits>
using namespace std;

// constant variable
// declare and initialize variable with number of vertices in graph
const int V = 5;

// function prototypes
int minDistance(int[], bool[]);
void printArray(int[], int);
void dijkstra(int[][V], int);

int main()
{
  // declare and initialize graph
  int graph[V][V] = {{0, 2, 0, 1, 0},
                     {2, 0, 3, 0, 0},
                     {0, 3, 0, 0, 4},
                     {1, 0, 0, 0, 2},
                     {0, 0, 4, 2, 0}};

  // function call
  dijkstra(graph, 0);

  return 0;
}


// function finds the vertex with minimum distance value from source
int minDistance(int distance[], bool shortestPathSet[])
{
  // declare and intialize variables
  int min = INT_MAX;
  int min_index = 0;

  // loop through all vertices to find vertex with minimum distance
  for (int vertex = 0; vertex < V; vertex++)
    {

      // updates min variables if distance is less than or equal to current min
      if (!shortestPathSet[vertex] && distance[vertex] <= min)
      {
        min = distance[vertex];
        min_index = vertex;
      }
    }

  // return index of vertex with minimum distance
  return min_index;
}


// function prints array of shortest distances from source vertex to all vertices
void printArray(int distance[], int n)
{ 
  cout << "Vertex     Distance from source" << endl;
  for (int i = 0; i < V; i++)
    cout << i << "          " << distance[i] << endl;
}


// function implements Dijkstra's shortest path algorithm 
void dijkstra(int graph[V][V], int src)
{
  // declare variables
  int distance[V];
  bool sptSet[V];

  // initialize all distances as infinite and sptSet[] as false
  for (int i = 0; i < V; i++)
  {
    distance[i] = INT_MAX;
    sptSet[i] = false;
  }

  // initialize distance of source vertex to itself as zero
  distance[src] = 0;

  // find the shortest path for all vertices
  for (int count = 0; count < V - 1; count++)
  {
    int u = minDistance(distance, sptSet);
    sptSet[u] = true;

    // update the distances from source to other vertices
    for (int v = 0; v < V; v++)
    {
      // updates v if conditions apply
      if (!sptSet[v] && graph[u][v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v])
        distance[v] = distance[u] + graph[u][v];
    }
  }

  // print array containing the minimum distances from source vertex to other vertices
  printArray(distance, V);
}

