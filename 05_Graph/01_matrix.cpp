/**
 * 有向图的邻接矩阵表示
*/
#include <iostream>

using namespace std;

#define MAXN 100

// 矩阵
int graph[MAXN][MAXN] = {0};

// 一个有向无权图的例子
int N = 4; //节点个数
int M = 5; //边数
int edges[5][2] = {{0, 1}, {0, 2}, {0, 3}, {2, 3}, {1, 3}};

// 判断两个节点有没有连边
bool has_edge(int u, int v) {
    return (graph[u][v] > 0);
}

// 输出图中所有的边
void print_all_edges() {
    for (int u=0; u<N; u++) {
        for (int v=0; v<N; v++) {
            if (has_edge(u, v))
                printf("%d --> %d\n", u, v);
        }
    }
}

int main() {
    // 读取图
    for (int i=0; i<M; i++)
        graph[edges[i][0]][edges[i][1]] = 1;

    print_all_edges();
    return 0;
}