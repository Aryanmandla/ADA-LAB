#include<iostream>
using namespace std;
int binomialCoeff(int n,int k){
    int B[n+1][k+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(j==0 || i==j)
                B[i][j] = 1;
            else
                B[i][j] = B[i-1][j-1] + B[i-1][j];
        }
    }
    return B[n][k];
}
int main(){
    int n,k;
    cout<<"Enter the value of n and k: ";
    cin>>n>>k;
    int res = binomialCoeff(n,k);
    cout<<"Binomial Coefficient of n and k is: "<<res<<endl;
    return 0;
}