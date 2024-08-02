#include<iostream>
#include<climits>
#include<fstream>
using namespace std;

int n;
int graph[10][10];
int mst[10];
int parent[10];
int key[10];


void readGraph(){
	fstream infile;
	infile.open("d.txt", ios::in);
	infile >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			infile >> graph[i][j];
		}
	}
	infile.close();
}
void initialize(){
    for(int i=0;i<n;i++){
        mst[i]=0;
        key[i]=INT_MAX;
        parent[i]=0;
    }
}
int minimunKey(){
    int mn=INT_MAX;
    int mnInd;
    for(int i=0;i<n;i++){
        if(mst[i]==0 && key[i]<mn){
            mn=key[i];
            mnInd=i;
        }
    }
    return mnInd;
}
void djikshitra(){
    key[0]=0;
    parent[0]=-1;
    int edge;
    for(int i=0;i<n-1;i++){
        // select the vertex having minimum key and that is not added in the MST yet from the set of vertices
        edge=minimunKey();
        mst[edge]=1;
        for(int v=0;v<n;v++){
            if(graph[edge][v] && mst[v] == 0 && key[edge]+graph[edge][v] < key[v]){
                parent[v]=edge;
                key[v]=graph[edge][v]+key[edge];
            }
        }
    }
}

void printMST(int v){
    for(int i=0;i<n;i++){
        cout<<"The distance from source to "<<char('A'+i)<<" "<<key[i]<<endl;
    }
 }
int main(){
    readGraph();
    initialize();
    djikshitra();
    printMST(0);
    return 0;
}