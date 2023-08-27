#include<iostream>
#include<limits.h>
#define V 4
using namespace std;
void printMatrix(int T[V][V]){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(T[i][j]== INT_MAX){
                cout<<"Infinity\t";
            } else{
                cout<<T[i][j]<<"\t\t";
            }
        }
        cout<<endl;
    }
}
void warshall(int T[V][V]){
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                int t = T[i][j] + T[i][k]*T[k][j];
                T[i][j] = t?1:0;
            }
        }
    }
    printMatrix(T);
}
int main(){
    int T[V][V] = {{0,0,0,0},{0,0,1,1},{0,1,0,0},{1,0,1,0}};
    warshall(T);
    return 0;
}