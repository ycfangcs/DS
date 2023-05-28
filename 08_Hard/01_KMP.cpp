/**
* KMP
*/
#include <iostream>
#include <string>

using namespace std;

// 计算next数组
void getNext(string s, int next[]) {
    int i = 0, j = -1;
    next[0] = -1;
    
    while (i < s.length() - 1) {
        while (j >= 0 && s[i] != s[j]) {
            j = next[j];
        }

        i++;
        j++;

        next[i] = j;
    }
}

// KMP算法
int kmp(string s, string p) {
    int next[p.length()];
    getNext(p, next);

    // 输出next数组
    cout << "next: ";
    for (int x: next) {
        cout << x << " ";
    }
    cout << endl;

    int i = 0, j = 0;
    while(i < s.length()) {
        while (j >= 0 && s[i] != p[j]) {
            j = next[j];
        }

        i++;
        j++;

        if (j == p.length()) {
            // 匹配成功，返回下标
            return i - j;
        }
    }
    // 匹配失败，返回-1
    return -1;
}

int main() {
    string s = "abacababababca";
    string p = "ababca";
    cout << "s: " << s << endl;
    cout << "p: " << p << endl;
    cout << kmp(s, p) << endl;
    return 0;
}