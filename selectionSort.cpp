#include<iostream>
using namespace std;
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[min])
                min = j;
        }
        swap(arr[i],arr[min]);
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
    cout<<"Array before applying selection sort algorithm: ";
    printArr(a,n);
    selectionSort(a,n);
    cout<<"Array after applying selection sort algorithm: ";
    printArr(a,n);
    return 0;
}