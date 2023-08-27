#include<iostream>
using namespace std;
void rankSort(int arr[],int n){
    int rankArr[n];
    for(int i=0;i<n;i++){
        int rank = 0;
        for(int j=0;j<n;j++){
            if(arr[i]>arr[j]){
                rank++;
            }
        }
        rankArr[i] = rank;
    }
    int sortedArr[n];
    for(int i=0;i<n;i++){
        sortedArr[rankArr[i]] = arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i] = sortedArr[i];
    }
}
void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter the size of an array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of an array: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Applying rank sorting technique: \n";
    rankSort(a,n);
    printArr(a,n);
    return 0;
}