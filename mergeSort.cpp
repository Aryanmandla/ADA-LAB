#include<iostream>
using namespace std;
void merge(int arr[],int start,int mid,int end);
void mergeSort(int arr[],int start,int end){
    if(start < end){
        int mid = (start+end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
void merge(int arr[],int start,int mid,int end){
    int n1 = mid-start+1;
    int n2 = end-mid;
    int A[n1],B[n2];
    for(int i=0;i<n1;i++){
        A[i] = arr[start+i];
    }
    for(int i=0;i<n2;i++){
        B[i] = arr[mid+1+i];
    }
    int i=0,j=0;
    int k = start;
    while(i<n1 && j<n2){
        if(A[i] <= B[j]){
            arr[k] = A[i];
            i++;
        } else{
            arr[k] = B[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = A[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = B[j];
        j++;
        k++;
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
    cout<<"Array before applying merge sort algorithm: ";
    printArr(a,n);
    mergeSort(a,0,n-1);
    cout<<"Array after applying merge sort algorithm: ";
    printArr(a,n);
    return 0;
}