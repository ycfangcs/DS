#include <iostream>

using namespace std;

// c中的字符串
// 1. 字符串是以 '\0' 结尾的字符数组
// 2. 字符串的长度是不包括 '\0' 的
char str1[] = "hello";
char str2[] = {'h', 'e', 'l', 'l', 'o', '\0'};
char str3[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
char str4[6] = "hello";

// c++中的字符串
string str5 = "hello";

// 字符串的长度
int str1_len = sizeof(str1) / sizeof(char); // 6
int str2_len = sizeof(str2) / sizeof(char); // 6
int str3_len = sizeof(str3) / sizeof(char); // 6
int str4_len = sizeof(str4) / sizeof(char); // 6
int str5_len = str5.length(); // 5

int main() {
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 << endl;
    cout << str5 << endl;

    cout << str1_len << endl;
    cout << str2_len << endl;
    cout << str3_len << endl;
    cout << str4_len << endl;
    cout << str5_len << endl;

    return 0;
}