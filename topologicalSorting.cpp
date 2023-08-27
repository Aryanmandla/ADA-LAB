#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    int adj[n][n];
    cout<<"Enter the adjacency matrix: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }
    int indegree[n] = {0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==1){
                indegree[j]++;
            }
        }
    }
    int visited[n] = {0};
    int count = 0;
    cout<<"The topological ordering: "<<endl;
    while(count < n){
        for(int i=0;i<n;i++){
            if(indegree[i] == 0 && visited[i] == 0){
                cout<<i<<" ";
                visited[i] = 1;
            for(int j=0;j<n;j++){
                if(adj[i][j] == 1){
                    indegree[j]--;
                    }
                }
            }
        }
        count++;
    }
    return 0;
}