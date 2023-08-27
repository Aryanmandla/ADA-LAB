#include<iostream>
#include<limits.h>
#define V 6
using namespace std;
int minKey(int dist[V], bool splSet[V]){
    int min = INT_MAX,min_index;
    for(int v=0;v<V;v++){
        if(!splSet[v] && dist[v] <= min){
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[V],int graph[V][V]){
    cout<<"Edge\tWeight\n";
    for(int v=1;v<V;v++){
        cout<<parent[v]<<" - "<<v<<" \t"<<graph[v][parent[v]]<<endl;
    }
}

void primMST(int graph[V][V]){
    int parent[V];
    int key[V];
    bool mstSet[V];

    for(int i=0;i<V;i++){
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    for(int count = 0;count<V-1;count++){
        int u = minKey(key,mstSet);
        mstSet[u] = true;

        for(int v=0;v<V;v++){
            if(!mstSet[v] && graph[u][v] && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent,graph);
}
int main(){
     int graph[V][V] = { { 0, 2, 0, 6, 0 },{ 2, 0, 3, 8, 5 },{ 0, 3, 0, 0, 7 },{ 6, 8, 0, 0, 9 },{ 0, 5, 7, 9, 0 } };
        primMST(graph);
    return 0;
}