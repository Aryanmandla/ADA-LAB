#include<iostream>
#include<limits.h>
#define V 4
using namespace std;
void printSolution(int dist[][V]);
void floydWarshall(int dist[][V]){
    int i,j,k;
    for(k=0;k<V;k++){
        for(i=0;i<V;i++){
            for(j=0;j<V;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j] && (dist[k][j] != INT_MAX && dist[i][k] != INT_MAX))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}
void printSolution(int dist[][V]){
    cout<<"The following matrix shows the shortest distances from every pair of vertices\n";
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j] == INT_MAX){
                cout<<" inf ";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}
int main(){
    int graph[][V] = {
        {0,3,INT_MAX,7},
        {8,0,2,INT_MAX},
        {5,INT_MAX,0,1},
        {2,INT_MAX,INT_MAX,0}
    };
    floydWarshall(graph);
    return 0;
}