// TIME COMPLEXITY : O(V+E)

#include<iostream>
#include<fstream>
using namespace std;
int n;
int g[4][4];    // Adjacency matrix to store the graph
int stack[4];       // Stack to store vertices for DFS
int top = -1;         // Stack pointer
int visited[4];
void readgraph(){
    fstream input;
    input.open("dfs.txt",ios::in);
    input>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            input >> g[i][j];
        }
    }
    input.close();
}

void push(int v) {
    stack[++top] = v;
}

int pop() {
    return stack[top--];
}

bool isStackEmpty() {
    return top == -1;
}
void dfs(int start, int n) {
    for (int i = 0; i <= n; i++) {
        int visited[i] = {0};
    }
    push(start);
    visited[start] = 1;
    while (!isStackEmpty()) {
        int u = pop();  
        std::cout << u << " ";
        for (int v =1; v <= n; v++) {
            if (g[u][v] && !visited[v]) {  // Check if w is adjacent to u and not visited
                visited[v] = 1;
                push(v);  
            }
        }
    }
}
int main() {
    readgraph();
    int start;
    cout<<"Starting index: ";
    cin >> start;
    cout << "DFS traversal starting from vertex "<< start <<":\n";
    dfs(start,n);
    cout<<endl;
    return 0;
}