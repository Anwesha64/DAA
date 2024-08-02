#include<iostream>
#include<limits.h>
using namespace std;

// function to find the most efficient way to multiply given sequence of matrices

int matrixchain(int arr[], int n){
    int dp[n][n];
    // min  cost required to multiplication
    // base case
    for(int i=0;i<n;i++)
        dp[i][i] = 0;
    for(int i=n;i>=0 ;i--){
        for(int j=i+1; j<n; j++){
            int mini = INT_MAX;
            for(int k=i; k<j; k++){
                int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                if(steps < mini) mini =steps;
            }
            dp[i][j] = mini;
        }

    }
    return dp[1][n-1];
}

int main(){
    int arr[] = {10,20,30,20,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Given afrrray :";
    for(int i=0; i<n; i++)
    cout << arr[i] << " ";
    cout << "\nMin number of multiplications is: "<<matrixchain(arr,n);
    return 0;
}