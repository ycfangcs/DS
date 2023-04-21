/**
 * Floyd算法
*/
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 100

// 邻接矩阵
int graph[MAXN][MAXN];

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
    for (int i=0; i<N; i++) 
        for (int j=0; j<N; j++)
            graph[i][j] = 0x3f3f3f3f; // 用一个很大的数表示无穷大
    for (int i=0; i<N; i++) 
        graph[i][i] = 0; // 自己到自己的距离为0
    for (int i=0; i<M; i++) 
        graph[edges[i][0]][edges[i][1]] = edges[i][2];
}

// Floyd算法
void floyd() {
    // 三重循环
    for (int k=0; k<N; k++) // 中间节点
        for (int i=0; i<N; i++) // 起点
            for (int j=0; j<N; j++) // 终点
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main() {
    init_graph();
    floyd();
    cout << "Floyd算法距离矩阵结果：" << endl;
    // 输出距离，如果为0x3f3f3f3f则代表"inf"
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (graph[i][j] == 0x3f3f3f3f) cout << "inf" << "\t";
            else cout << graph[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}