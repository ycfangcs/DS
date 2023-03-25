#include <iostream>

using namespace std;

// 链表的定义
struct Node
{
    int data;
    Node *next;
};

typedef Node *LinkList;

// 初始化链表（带头结点）
void initList(LinkList &L)
{
    L = new Node;
    // 头结点的data域可以不存储数据
    L->data = 0;
    // "->"是指针的运算符，表示指针指向的结构体的成员
    L->next = nullptr;
}

// 判断链表是否为空
bool isEmpty(LinkList L)
{
    return L->next == nullptr;
}

// 在链表的第i个位置插入元素e
bool insertList(LinkList &L, int i, int e)
{   
    // 如果i小于1，那么插入失败，因为链表的第一个元素是第1个
    if (i < 1)
    {
        return false;
    }
    Node *p = L;
    int j = 0;

    // 找到第i-1个结点
    while (p != nullptr && j < i - 1)
    {
        p = p->next;
        j++;
    }

    // 如果i大于链表的长度，则插入失败
    if (p == nullptr)
    {
        return false;
    }

    // 初始化新结点
    Node *s = new Node;
    s->data = e;
    // 插入新结点
    s->next = p->next; // 先把新结点的next指针指向p的next指针指向的结点
    p->next = s; // 再把p的next指针指向新结点

    // 插入成功
    return true;
}

// 删除链表的第i个元素
bool deleteList(LinkList &L, int i, int &e)
{
    // 如果i小于1，那么删除失败，因为链表的第一个元素是第1个
    if (i < 1)
    {
        return false;
    }
    Node *p = L;
    int j = 0;

    // 找到第i-1个结点
    while (p != nullptr && j < i - 1)
    {
        p = p->next;
        j++;
    }

    // 如果i大于链表的长度，则删除失败
    if (p == nullptr)
    {
        return false;
    }

    // 这里要暂存一下p->next，方便后面释放内存
    Node *q = p->next; // q指向第i个结点，即要删除的结点

    // 如果q为空，说明链表中没有第i个结点
    if (q == nullptr)
    {   
        // 删除失败
        return false;
    }

    // 删除结点
    p->next = q->next;
    delete q; // 释放结点的内存

    // 删除成功
    return true;
}

// 遍历链表
void traverseList(LinkList L)
{
    Node *p = L->next;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 获取链表的长度
int getLength(LinkList L)
{
    int length = 0;
    Node *p = L->next;
    while (p != nullptr)
    {
        length++;
        p = p->next;
    }
    return length;
}

// 获取链表的第i个元素
int getElem(LinkList L, int i)
{
    // 如果i小于1，那么获取失败，因为链表的第一个元素是第1个
    if (i < 1)
    {
        // 用-1表示获取失败
        return -1;
    }
    Node *p = L;
    int j = 0;

    // 找到第i个结点
    while (p != nullptr && j < i)
    {
        p = p->next;
        j++;
    }

    // 如果i大于链表的长度，则获取失败
    if (p == nullptr)
    {
        return -1;
    }

    // 获取成功
    return p->data;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkList L; // 定义一个链表
    initList(L); // 初始化链表
    // 将数组a中的元素全都插入到链表中（头插法）
    for (int i = 0; i < 9; i++)
    {   
        // 头插法，每次都插入到第1个位置
        insertList(L, 1, a[i]);
    }
    traverseList(L); // 遍历链表
    cout << "链表的长度为：" << getLength(L) << endl;
    cout << "链表的第3个元素为：" << getElem(L, 3) << endl;

    return 0;
}
