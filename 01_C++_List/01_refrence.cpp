#include <iostream>

using namespace std;

// 使用引用来加一，可以改变a的值
void addOneReference(int &a)
{
    a++;
}

// 这样加一不会改变a的值
void addOne(int a)
{
    a++;
}

int main(int argc, char const *argv[])
{
    int a = 10;
    int &b = a;

    cout << "开始时：" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    b = 20;
    cout << "b = 20后：" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    addOne(a);
    cout << "使用addOne(a)后：" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    addOneReference(a);
    cout << "使用addOneReference(a)后：" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}
