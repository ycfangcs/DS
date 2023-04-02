#include <iostream>

using namespace std;

// 栈的定义
#define MAX_SIZE 100 // 栈的最大容量

int stack[MAX_SIZE];
int top = -1; // 初始值为-1表示这个栈目前是空栈

// 判断栈是否为空
bool isEmpty() {
    return top == -1;
}

// 判断栈是否已满
bool isFull() {
    return top == MAX_SIZE - 1;
}

// 获取栈顶元素
int peek() {
    if (isEmpty()) {
        cout << "错误：栈为空" << endl;
        return -1;
    } else {
        return stack[top];
    }
}

// 按顺序输出栈中的所有元素
void displayStack() {
    if (isEmpty()) {
        cout << "栈为空" << endl;
    } else {
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

// 将元素压入栈
void push(int value) {
    if (isFull()) {
        cout << "错误：栈已满" << endl;
    } else {
        stack[++top] = value; // 先将top加1，再将元素压入栈
        // 等价于以下代码：
        // top++;
        // stack[top] = value;
        cout << "已把" << value << "压入栈中" << endl;
    }
}

// 将栈顶元素弹出栈，并返回其值
int pop() {
    if (isEmpty()) {
        cout << "错误：栈为空" << endl;
        return -1;
    } else {
        int value = stack[top--]; // 先将栈顶元素取出，再将top减1
        // 等价于以下代码：
        // int value = stack[top];
        // top--;
        cout << "弹出栈顶元素：" << value << endl;
        return value;
    }
}

int main() {
    // 使用示例代码
    push(3);
    push(7);
    push(2);
    displayStack(); // 打印栈中元素，输出: Stack elements: 3 7 2
    cout << "栈顶元素为：" << peek() << endl; // 输出: 栈顶元素为：2
    pop();
    pop();
    displayStack(); // 打印栈中元素，输出: Stack elements: 3
    cout << "栈顶元素为：" << peek() << endl; // 输出: 栈顶元素为：3
    
    return 0;
}
