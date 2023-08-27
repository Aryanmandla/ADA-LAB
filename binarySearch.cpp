#include<iostream>
using namespace std;
void sortingArr(int arr[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
                if(arr[i] > arr[j]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
        }
    }
}

int binarySearch(int arr[], int size, int key){
    int low = 0;
    int high = size-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return 0;
}

void printArr(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n,key;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of an array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Sorting the array in ascending order: ";
    sortingArr(arr,n);
    printArr(arr,n);
    cout<<"Enter the key to search: ";
    cin>>key;
    int res = binarySearch(arr,n,key);
    if(res == 0){
        cout<<"Key not found\n";
    } else{
        cout<<"Key found at index: "<<res<<endl;
    }
    return 0;
}