#include<iostream>
using namespace std;
#define I 450
const int n=4;
int mat[4][4]={{0,3,I,7},{8,0,2,I},{5,I,0,1},{2,I,I,0}};

void solve(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }
}
void display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<i<<"-->"<<j<<" ";
            cout<<mat[i][j]<<" ";
         }
        cout<<endl;
    }
}
int main(){
    solve();
    display();
}
