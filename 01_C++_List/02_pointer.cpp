#include <iostream>

using namespace std;

// 例1.取一个变量的指针，指针相当于变量的地址
void example1()
{
    int a = 10; // 定义一个变量a
    int *p = &a; // 定义一个指针p，指向变量a，这里的"&"表示取变量的地址
    cout << "a = " << a << endl;
    cout << "p = " << p << endl; // 指针p的值是变量a的地址，是一个八字节的十六进制数
    cout << "*p = " << *p << endl; // 用*p来取指针p指向的变量的值
}

// 例2.指针的指针
void example2()
{
    int a = 10;
    int *p = &a;
    int **pp = &p; // 定义一个指针的指针pp，指向指针p
    cout << "a = " << a << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    cout << "pp = " << pp << endl;
    cout << "*pp = " << *pp << endl;
    cout << "**pp = " << **pp << endl;
}

// 例3.数组与指针的关系
void example3()
{
    int a[5] = {1, 2, 3, 4, 5};
    int *p = a; // 数组名a就是数组的首地址，所以可以直接赋值给指针p
    cout << "a = " << a << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    cout << "*a = " << *a << endl;
    cout << "*(p + 1) = " << *(p + 1) << endl; // p+1表示指针p指向的变量的下一个变量的地址
    cout << "*(p + 2) = " << *(p + 2) << endl;
    cout << "*(p + 3) = " << *(p + 3) << endl;
    cout << "*(p + 4) = " << *(p + 4) << endl;
    p++; // 可以用p++把指针p指向下一个变量
    cout << "p++后：" << *p <<endl;
}

// 例4.二维数组与指针的关系
void example4()
{
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int *p = a[0]; // 把数组第一行的首地址赋值给指针p
    cout << "a = " << a << endl;
    cout << "p = " << p << endl;
    cout << "*a = " << *a << endl; // *a表示二维数组的第一行
    cout << "a[0] = " << a[0] << endl;
    cout << "*p = " << *p << endl;
    cout << "*(p + 1) = " << *(p + 1) << endl;
    cout << "**(a + 1) = " << **(a + 1) << endl; // *(a + 1)表示二维数组的第二行)"

}

int main(int argc, char const *argv[])
{
    cout << "********** 例1 **********" << endl;
    cout << "a是变量，p是指针，*p是指针p指向的变量的值" << endl;
    example1();

    cout << "********** 例2 **********" << endl;
    cout << "pp是指针的指针，**pp是指针pp指向的指针指向的变量的值" << endl;
    example2();

    cout << "********** 例3 **********" << endl;
    cout << "a是一维数组，p是指向数组第一个值的指针" << endl;
    example3();

    cout << "********** 例4 **********" << endl;
    cout << "a是二维数组，p是指向数组第一行的指针" << endl;
    example4();
    return 0;
}
