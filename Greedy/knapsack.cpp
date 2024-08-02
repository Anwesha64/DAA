#include<iostream>
using namespace std;

const int n = 3;
int weight = 50;
int Profit[] = {60, 100, 120};
int Weight[] = {10, 20, 30};

struct knapsack{
    int profit;
    int weight;
    double ratio;
};

struct knapsack arr[n] = {0};

void initialize(){
    for(int i=0; i<n; i++){
        arr[i].profit = Profit[i];
		arr[i].weight = Weight[i];
		arr[i].ratio = (double)Profit[i]/Weight[i];
    }
}

void bubbleSort(){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-i-1; j++){
			if(arr[j].ratio < arr[j+1].ratio){
				swap(arr[j],arr[j+1]);
			}
		}	 
	}
}

void fractionalknapsack(){
    initialize();
    bubbleSort();
    double profit = 0;
    for(int i=0; i<n; i++){
        if(weight>0){
            int takenweight = min(weight,arr[i].weight);
            profit += takenweight * arr[i].ratio;
            weight -= takenweight;
        }
    }
    cout<<"The total profit will be: "<<profit<<endl;
}

int main(){
    fractionalknapsack();
    return 0;
}