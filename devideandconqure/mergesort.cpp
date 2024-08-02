#include<iostream>
using namespace std;

void printarray(int arr[],int size){
    for(int i=0;i<size;++i){
        cout << arr[i] <<" ";
    }
    cout << endl;
}
void merge(int low,int mid,int high,int arr[]){
    int i,j,k;
    i=low,j=mid+1,k=low;
    int b[high];
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            b[k++]=arr[i++];
        }else{
            b[k++]=arr[j++];
        }
    }
    // add the remaining elements 
    for(;i<=mid;i++) b[k++]=arr[i];
    for(;j<=high;j++) b[k++]=arr[j];

    // coping the elements in arr from b arr
    for(int i=low;i<=high;i++){
        arr[i]=b[i];
    }

    // printarray(arr,high+1);
    cout<<"\nmerging: ";
    printarray(arr+low, high-low+1);
}
void mergeSort(int low,int high,int arr[]){
    if(low<high){
        int mid=(low+high)/2;
        cout<<"\nDividing: ";
        printarray(arr+low, high-low+1);
        mergeSort(low,mid,arr);
        mergeSort(mid+1,high,arr);
        merge(low,mid,high,arr);
    }
}
int main(){
    int arr[]={80,26,90,10,20,22};
    int size=sizeof(arr)/sizeof(int);
    cout<<"Given array: ";
    printarray(arr,size);
    int low=0,high=size-1;
    mergeSort(low,high,arr);
    cout<<"sorted array: ";
    printarray(arr,size);
}