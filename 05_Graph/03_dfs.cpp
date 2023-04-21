/**
 * 深度优先搜索 DFS
*/
#include <iostream>
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


// DFS整体流程
bool visited[MAXN] = {false};

void visit(int u) {
    printf("访问了节点%d\n", u);
}

void dfs(int u) {    
    visit(u);
    visited[u] = true;

    for (int v:graph[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void dfs_all() {
    for (int u=0; u<N; u++){
        if (!visited[u]) {
            printf("\n从节点%d开始dfs...\n", u);
            dfs(u);
        }
        else {
            printf("\n因为节点%d已经访问过了，所以不从它开始dfs\n", u);
        }
    }
}

int main() {
    // 读取图
    for (int i=0; i<M; i++) 
        graph[edges[i][0]].push_back(edges[i][1]);
    
    dfs_all();
    return 0;
}