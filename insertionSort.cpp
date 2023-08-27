#include<iostream>
using namespace std;
/* utilities functions */
void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
/* insertion sort */
void insertionSort(int arr[], int n){
    for(int j=1;j<n;j++){
        int temp = arr[j];
        int i = j-1;
        while(i>=0 && arr[i] > temp){
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = temp;
    }
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
    cout<<"Array before sorting: ";
    printArr(a,n);
    insertionSort(a,n);
    cout<<"Array after sorting: ";
    printArr(a,n);
    return 0;
}