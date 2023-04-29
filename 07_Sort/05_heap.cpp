/**
 * 二叉堆
*/
#include <iostream>

using namespace std;

int arr[] = {3, 1, 5, 7, 2, 4, 9, 6, 10, 8};
int num = 10;

const int MAXN = 1000; // 最大元素个数
int heap[MAXN], n = 10; // 堆的存储，堆中元素个数

// 下沉调整
void downAdjust(int low, int high) {
    int i = low, j = i * 2; // j是i的左子节点
    while (j <= high) {
        // 如果右子节点比左子节点大，就让j指向右子节点
        if (j + 1 <= high && heap[j + 1] > heap[j]) {
            j = j + 1;
        }
        if (heap[j] > heap[i]) { // 如果子节点比父节点大，就交换
            swap(heap[j], heap[i]);
            i = j; // i指向j，继续循环
            j = i * 2; // j指向i的左子节点
        } else { // 否则，父节点比子节点大，下沉完毕
            break;
        }
    }
}

// 上浮调整
void upAdjust(int low, int high) {
    int i = high, j = i / 2; // j是i的父节点
    while (j >= low) {
        if (heap[j] < heap[i]) { // 如果父节点比子节点小，就交换
            swap(heap[j], heap[i]);
            i = j;
            j = i / 2;
        } else { // 否则，父节点比子节点大，上浮完毕
            break;
        }
    }
}

// 建堆
void createHeap(int n) {
    for (int i = n / 2; i >= 1; i--) {
        downAdjust(i, n);
    }
}

// 删除堆顶元素
void deleteTop() {
    heap[1] = heap[n--];
    downAdjust(1, n);
}

// 添加元素
void insert(int x) {
    heap[++n] = x;
    upAdjust(1, n);
}

// 堆排序
void heapSort(int n) {
    // 数组arr从1开始存储，n是元素个数
    createHeap(n); // 建堆
    for (int i = n; i > 1; i--) { // 这里的i是堆中元素个数
        // 删除堆顶元素，将堆顶元素与最后一个元素交换，然后把堆顶元素下沉
        swap(heap[i], heap[1]); 
        downAdjust(1, i - 1); // 这里的i-1是交换后的堆中元素个数
    }
}

int main() {
    for (int i = 1; i <= n; i++) {
        heap[i] = arr[i - 1];
    }
    heapSort(n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", heap[i]);
    }
    return 0;
}