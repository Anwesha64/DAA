#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;  //initialize as largest root
    int left = 2 * i + 1;  //left child
    int right = 2 * i + 2;  //right child

    if(left < n && arr[left] > arr[largest])  
        largest = left;
    if(right < n && arr[right] > arr[largest])  
        largest = right;

    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[], int n){
    for(int i=n-2; i>=0; i--)
        heapify(arr,i,n);
    for(int i=n-1; i>0; i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[]={12,11,13,5,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Original array: ";
    printArray(arr,n);
    heapSort(arr,n);
    cout<<"After sorting: ";
    printArray(arr,n);
    return 0;
}

