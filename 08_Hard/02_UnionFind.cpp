/**
 * 并查集
*/
#include <iostream>

using namespace std;

const int N = 10010; // 最大节点数

int n;
int p[N];

// 初始化
void Init() {
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
}

// 返回x对应集合的根节点
int Find(int x) {
    // 路径压缩
    if (p[x] != x) {
        p[x] = Find(p[x]);
    }
    return p[x];
}

// 合并x和y对应的集合
void Union(int x, int y) {
    p[Find(x)] = Find(y);
}

int main() {
    n = 10;
    Init();
    Union(1, 2);
    Union(3, 4);
    Union(5, 6);
    Union(1, 6);
    for (int i = 1; i <= n; i++) {
        cout << Find(i) << " ";
    }
    return 0;
}