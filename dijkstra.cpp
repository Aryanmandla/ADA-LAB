#include<iostream>
#include<limits.h>
#define V 6
using namespace std;
/*function to find the index of vertex with minimum distance value*/
int minimumDistance(int dist[],bool splset[]){
    int min = INT_MAX;
    int min_index;
    for(int v=0;v<V;v++){
        if(!splset[v] && dist[v] <= min){
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
/*function to print the distances from the source vertex*/
void printSolution(int dist[]){
    cout<<"Vertex \t Distance from the source"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<"\t\t\t\t"<<dist[i]<<endl;
    }
}
/*dijkstra algorithm to find the shortest distance from the source vertes*/
void dijkstraAlgo(int graph[V][V],int src){
    int dist[V];
    bool splset[V];

    for(int i=0;i<V;i++){
        dist[i] = INT_MAX;
        splset[i] = false;
    }

    dist[src] = 0;

    for(int count = 0;count<V-1;count++){
        int u = minimumDistance(dist,splset);
        splset[u] = true;

        for(int v=0;v<V;v++){
            if(!splset[v] && graph[u][v] &&dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    printSolution(dist);
}

int main(){
    int graph[V][V] = {
        {0,3,2,5,0,0},
        {3,0,0,1,4,0},
        {2,0,0,2,0,1},
        {5,1,2,0,3,0},
        {0,4,0,3,0,2},
        {0,0,1,0,2,0}
    };

    dijkstraAlgo(graph,0);
    return 0;
}