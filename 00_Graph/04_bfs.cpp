#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAXN 100

// 邻接表
vector<int> graph[MAXN];

// 一个有向无权图的例子
int N = 8; //节点个数
int M = 8; //边数
int edges[8][2] = {
    {0, 1}, 
    {0, 2}, 
    {1, 2}, 
    {1, 3}, 
    {2, 3}, 
    {2, 5},
    {3, 4},
    {7, 6}
};


// BFS整体流程
bool visited[MAXN] = {false};

void visit(int u) {
    printf("访问了节点%d\n", u);
}

// 从节点u开始bfs
void bfs(int u) {
    queue<int> que;
    que.push(u);
    visited[u] = true;

    while (que.size()) {
        int v = que.front();
        que.pop();

        // 访问
        visit(v);
        
        
        for (int t:graph[v])
            if (!visited[t])
                visited[t] = true, que.push(t);
    }
}

// BFS所有节点
void bfs_all() {
    for (int u=0; u<N; u++){
        if (!visited[u]) {
            printf("\n从节点%d开始bfs...\n", u);
            bfs(u);
        }
        else {
            printf("\n因为节点%d已经访问过了，所以不从它开始bfs\n", u);
        }
    }
}

int main() {
    // 读取图
    for (int i=0; i<M; i++) 
        graph[edges[i][0]].push_back(edges[i][1]);
    
    bfs_all();
    return 0;
}