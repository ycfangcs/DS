#include <iostream>

using namespace std;

// 队列的定义
#define MAX_QUEUE_SIZE 100 // 数组最大容量

int queue[MAX_QUEUE_SIZE];
int front = 0; // 队首索引
int rear = 0;  // 队尾索引

// 判断队空
bool is_queue_empty() {
    return front == rear;
}

// 判断队满
bool is_queue_full() {
    return (rear + 1) % MAX_QUEUE_SIZE == front;
}

// 入队操作
void enqueue(int value) {
    if (is_queue_full()) {
        cout << "队满了！" << endl;
        return;
    }

    queue[rear] = value;
    
    rear = (rear + 1) % MAX_QUEUE_SIZE;

    cout << value << "已加入队列中" << endl;
}

// 出队操作
void dequeue() {
    if (is_queue_empty()) {
        cout << "失败：队列为空！" << endl;
        return;
    }

    int dequeued_value = queue[front];

    front = (front + 1) % MAX_QUEUE_SIZE;

    cout << dequeued_value << " 已从队列里出队" << endl;
}

// 获取队首元素
int get_front() {
    if (is_queue_empty()) {
        cout << "错误：队列为空！" << endl;
        return -1;
    }
    
    // 队首元素的索引是 front
    return queue[front];
}

// 获取队尾元素
int get_rear() {
    if (is_queue_empty()) {
        cout << "错误：队列为空！" << endl;
        return -1;
    }

    // 队尾元素的索引是 rear - 1
    return queue[(rear - 1) % MAX_QUEUE_SIZE];
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    dequeue();
    dequeue();

    cout << "队首元素: " << get_front() << endl;
    cout << "队尾元素: " << get_rear() << endl;

    // 测试队空
    // for (int i=0; i<10; i++) {
    //     dequeue();
    // }

    // 测试队满
    // for (int i=0; i<101; i++) {
    //     enqueue(i);
    // }

    return 0;
}