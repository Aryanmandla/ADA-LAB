#include <bits/stdc++.h>
using namespace std;
int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while(arr[i] <= pivot && i < high){
            i++;
        }
        while(arr[j] > pivot && j > low){
            j--;
        }
        if(i < j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(int arr[],int low,int high){
    if(low < high){
    int part = partition(arr,low,high);
    quickSort(arr,low,part-1);
    quickSort(arr,part+1,high);
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
    cout<<"Array before applying quick Sort Technique: \n";
    printArr(a,n);
    quickSort(a,0,n-1);
    cout<<"Array after applying quick Sort Technique: \n";
    printArr(a,n);
    return 0;
}