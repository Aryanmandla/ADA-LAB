#include<iostream>
#include<climits>
#define V 5
using namespace std;
int parent[V];
int find(int x){
    while(parent[x] != x){
        x = parent[x];
    }
    return x;
}

void union1(int x,int y){
    int a = find(x);
    int b = find(y);

    parent[a] = b;
}

void kruskalAlgo(int cost[V][V]){
    int minCost = 0;
    for(int i=0;i<V;i++){
        parent[i] = i;
    }
    int count = 0;
    while(count < V-1){
        int min = INT_MAX,a = -1, b = -1;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(find(i) != find(j) && cost[i][j] < min){
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        union1(a,b);
        cout<<"Edge "<<count++<<" : ("<<a<<" - "<<b<<")"<<min<<endl;
        minCost += min;
    }
    cout<<"Minimum Spanning Cost: "<<minCost<<endl;
}
int main(){
    int graph[V][V] = { { INT_MAX, 2, INT_MAX, 6, INT_MAX },
                        { 2, INT_MAX, 3, 8, 5 },
                        { INT_MAX, 3, INT_MAX, INT_MAX, 7 },
                        { 6, 8, INT_MAX, INT_MAX, 9 },
                        { INT_MAX, 5, 7, 9, INT_MAX } };
    kruskalAlgo(graph);
    return 0;
}