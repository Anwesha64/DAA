// TIME COMPLEXITY : O(V+E)

#include<iostream>
#include<fstream>
using namespace std;
const int MAX = 100;  // Define a constant for maximum number of vertices
int n;
int q[MAX];
int g[MAX][MAX];
int front = 0, rear = 0;
int visited[MAX];
void readgraph() {
    fstream input;
    input.open("bfs.txt", ios::in);
    input >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            input >> g[i][j];
        }
    }
    input.close();
}

void push(int k) {
    q[rear++] = k;
}

int pop() {
    return q[front++];
}

bool empty() {
    return front == rear;
}
void bfs(int start, int n) {
    for (int i = 0; i <= n; i++) {
        visited[i] = 0;
    }
    push(start);
    visited[start] = 1;
    while (!empty()) {
        int u = pop();
        cout << u << " ";
        for (int v = 1; v <= n; v++) {
            if (g[u][v] && !visited[v]) {
                // push(v);
                visited[v] = 1;
                push(v);
            }
        }
    }
}

int main() {
    readgraph();
    int start;
    cout << "Starting index: ";
    cin >> start;
    cout << "BFS traversal starting from vertex " << start << ":\n";
    bfs(start, n);
    cout << endl;
    return 0;
}