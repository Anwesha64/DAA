#include <iostream>
using namespace std;

void printarray(int arr[],int size){
  for(int i=0; i<size; i++){
    cout << arr[i] <<" ";
  }
  cout << endl;
}

int partition(int arr[],int low,int high)
{
  int pivot=arr[high];
  int i=(low-1);
  int j=high;
  for(int j=low;j<=high;j++)
  { 
    if(arr[j]<pivot)
    {
      i++;
      swap(arr[i],arr[j]);
      cout<<"Swapped "<<arr[i]<<" and "<<arr[j]<<": ";
      printarray(arr+low,high-low+1);
    }
  }
  swap(arr[i+1],arr[j]);
  cout<<"Swapped pivot "<<arr[i+1]<<" with "<<arr[j]<<": ";
  printarray(arr,high+1);
  return (i+1);
}       
void quickSort(int arr[],int low,int high)
{
  if(low<high)
  {  
    int pi=partition(arr,low,high);
    cout<<"Pivot is at index: "<<pi<<endl;
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
}
             
 
int main() {
  int arr[]={10,7,8,9,1,5};
  int size=sizeof(arr)/sizeof(arr[0]);
  cout<<"Initial array: ";
  printarray(arr,size);
  quickSort(arr,0,size-1);
  cout<<"\nSorted Array\n";
  printarray(arr,size);
  return 0;
}

