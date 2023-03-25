#include <iostream>

using namespace std;

int global_array[5]; // 全局数组，如果没有初始化，那么数组的所有元素都是0

// 数组的定义
void example_array()
{
    int a[5] = {1, 2, 3, 4, 5}; // 定义一个长度为5的数组，数组的每个元素都是int类型
    int b[5] = {1, 2, 3}; // 如果没有初始化，那么数组的剩余元素会被初始化为0
    int c[5]; // 局部数组如果没有初始化，那么数组的所有元素都是随机值
    int d[] = {1, 2, 3, 4, 5}; // 如果在定义数组的时候没有指定数组的长度，那么编译器会自动计算数组的长度
    for (int x:a)
    {
        cout << x << " ";
    }
    cout << endl;
    for (int x:b)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "局部未初始化数组的元素：";
    for (int x:c)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "全局未初始化数组的元素：";
    for (int x:global_array)
    {
        cout << x << " ";
    }
    cout << endl;
}

// 顺序表的机试写法
void sequence_list()
{
    int a[100]; // 定义一个长度为100的数组
    int n; // 顺序表的长度

    // 读入顺序表的长度
    cout << "请输入顺序表的长度：" << endl;
    cin >> n;

    // 读入顺序表的元素
    cout << "请输入顺序表的元素：" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // 遍历顺序表的元素
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main(int argc, char const *argv[])
{
    cout << "********** 数组的定义 **********" << endl;
    example_array();

    cout << "********** 顺序表的机试写法 **********" << endl;
    sequence_list();
    return 0;
}
