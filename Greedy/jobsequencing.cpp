#include<iostream>
using namespace std;
const int n = 8;
int profit[]={20,60,70,65,25,80,10,22};
int deadline[]={4,5,6,6,4,2,2,2};

struct  job{
    int profit;
    int deadline;
};

struct job arr[n]={0};

void initialize(){
    for(int i=0;i<n;i++){
        arr[i].profit=profit[i];
        arr[i].deadline=deadline[i];
    }
}
void display(){
    for(int i=0;i<n;i++){
        cout<<"("<<arr[i].deadline<<","<<arr[i].profit<<")"<<" ";
    }
    cout<<endl;
}


void bubblesort(){
    for(int i=0;i<n-1;i++){
        for(int j=0; j<n-i-1;j++){
            if(arr[j].profit<arr[j+1].profit){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int getmax(){
    int mx = arr[0].deadline;
    for(int i=0;i<n;i++){
        if(arr[i].deadline>mx){
            mx=arr[i].deadline;
        }
    }
    return mx;
}

void job(){
    initialize();
    display();
    bubblesort();
    int size=getmax();
    int x[size];
    for(int i=0;i<size;i++) 
        x[i]=-1;
    int ans=0;      //profit
    for(int i=0;i<n;i++){   
        for(int j=arr[i].deadline;j>=0;j--){
            if(x[j]==-1){
                x[j]=i;
                ans+=arr[i].profit;
                break;
            }
        }
    }
    cout<<"Profit:-"<<ans;
}
int main(){
    job();
    return 0;
}
