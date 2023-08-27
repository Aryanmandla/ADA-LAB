#include<iostream>
#include<vector>
using namespace std;
void printMatrix(vector<vector<int>>& graph){
    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph.size();j++){
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

void transitiveClosure(vector<vector<int>>& graph){
    vector<vector<int>> reach(graph.size(),vector<int>(graph.size()));
    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph.size();j++){
            reach[i][j] = graph[i][j];
         }
    }
    
    for(int k=0;k<graph.size();k++){
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph.size();j++){
                reach[i][j] = reach[i][j] ||(reach[i][k] && reach[k][j]);
            }
        }
    }
    printMatrix(reach);
}
int main(){
    vector<vector<int>>graph={{0,1,0},{0,0,1},{1,0,0}};
    transitiveClosure(graph);
    return 0;
}