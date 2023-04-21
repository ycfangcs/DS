/**
 * 邻接表
*/
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 100

// 邻接表
vector<int> graph[MAXN];

// 一个有向无权图的例子
int N = 4; //节点个数
int M = 5; //边数
int edges[5][2] = {{0, 1}, {0, 2}, {0, 3}, {2, 3}, {1, 3}};

// 判断两个节点有没有连边
bool has_edge(int u, int v) {
    vector<int> &edges_of_u = graph[u];
    for (int x:edges_of_u)
        if (x == v)
            return true;
    return false;
}

// 输出图中所有的边
void print_all_edges() {
    for (int u=0; u<N; u++) {
        for (int v:graph[u]) {
            printf("%d --> %d\n", u, v);
        }
    }
}

int main() {
    // 读取图
    for (int i=0; i<M; i++) 
        graph[edges[i][0]].push_back(edges[i][1]);
    
    print_all_edges();
    return 0;
}