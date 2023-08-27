#include<iostream>
using namespace std;
int knapsack(int n,int m,int W[],int P[]){
    int V[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int w=0;w<=m;w++){
            if(i==0 || w==0){
                V[i][w] = 0;
            } else if(W[i] > w){
                V[i][w] = V[i-1][w];
            } else{
                V[i][w] = max(V[i-1][w],V[i-1][w-W[i]]+P[i]);
            }
        }
    }
    return V[n][m];
}
int main(){
    int n,m;
    cout<<"Enter the number of objects: ";
    cin>>n;
    cout<<"Enter the maximum capacity: ";
    cin>>m;
    int W[n];
    int P[n];
    W[0] = -1;
    P[0] = -1;
    for(int i=1;i<=n;i++){
            cout<<"Enter Weight and Profit of object "<<i<<": ";
            cin>>W[i]>>P[i];
    }
    int res = knapsack(n,m,W,P);
    cout<<"Result: "<<res<<endl;
    return 0;
}