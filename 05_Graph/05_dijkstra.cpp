/**
 * Dijkstra算法
*/
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 100

// 邻接表
vector<int> graph[MAXN];

// 一个有向有权图
int N = 6; //节点个数
int M = 9; //边数
int edges[9][3] = {
    {0, 1, 10}, 
    {0, 4, 15}, 
    {1, 2, 15}, 
    {1, 3, 2}, 
    {2, 5, 5}, 
    {3, 2, 1}, 
    {3, 5, 12},
    {4, 5, 10},
    {4, 3, 5}
};

// 初始化图
void init_graph() {
    for (int i=0; i<M; i++) 
        graph[edges[i][0]].push_back(edges[i][1]);
}

// Dijkstra算法所需的数组
int dist[MAXN]; // 距离数组
bool visited[MAXN] = {false}; // 是否已经访问过

// 找到距离最小的节点
int find_min_dist() {
    int min_dist = 0x3f3f3f3f; // 用一个很大的数表示无穷大
    int min_node = -1;
    for (int i=0; i<N; i++) {
        if (!visited[i] && dist[i] < min_dist) {
            min_dist = dist[i];
            min_node = i;
        }
    }
    return min_node;
}

// Dijkstra算法
void dijkstra(int start) {
    // 初始化距离数组
    for (int i=0; i<N; i++) 
        dist[i] = 0x3f3f3f3f; // 用一个很大的数表示无穷大
    dist[start] = 0; // 起点到自己的距离为0

    // 找到距离最小的节点
    for (int i=0; i<N; i++) {
        int u = find_min_dist();
        visited[u] = true;
        for (int j=0; j<graph[u].size(); j++) {
            int v = graph[u][j];
            // 如果v没有被访问过，并且u到v的距离小于v原来的距离
            if (!visited[v] && dist[u] + edges[u][v] < dist[v])
                dist[v] = dist[u] + edges[u][v]; // 更新v的距离
        }
        // 可以简化成以下代码
        // for (int v:graph[u]) {
        //     if (!visited[v] && dist[u] + edges[u][v] < dist[v])
        //         dist[v] = dist[u] + edges[u][v]; // 更新v的距离
        // }
    }
}

int main() {
    init_graph();
    dijkstra(0);
    cout << "从0出发的最短距离为：" << endl;
    for (int i=0; i<N; i++) 
        cout << dist[i] << " ";
    cout << endl;
    for (auto e:edges)
        cout << e[0] << " " << e[1] << " " << e[2] << endl;
    return 0;
}