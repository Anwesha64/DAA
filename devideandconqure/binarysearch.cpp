#include<iostream>
using namespace std;

int binarysearch(int arr[], int left, int right, int target){
    while(left<=right){
        int mid = left + (right-left)/2;

        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]<target)
            left = mid+1;
        else
            right = mid-1;
        }
        return -1;
    
}
int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = binarysearch(arr, 0, n - 1, target);
    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";
    return 0;
}
