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
    int i = low, j = i * 2;
    while (j <= high) {
        if (j + 1 <= high && heap[j + 1] > heap[j]) {
            j = j + 1;
        }
        if (heap[j] > heap[i]) {
            swap(heap[j], heap[i]);
            i = j;
            j = i * 2;
        } else {
            break;
        }
    }
}

// 上浮调整
void upAdjust(int low, int high) {
    int i = high, j = i / 2;
    while (j >= low) {
        if (heap[j] < heap[i]) {
            swap(heap[j], heap[i]);
            i = j;
            j = i / 2;
        } else {
            break;
        }
    }
}

// 建堆
void createHeap(int arr[], int n) {
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
void heapSort(int arr[], int n) {
    createHeap(arr, n);
    for (int i = n; i > 1; i--) {
        swap(arr[i], arr[1]);
        downAdjust(1, i - 1);
    }
}

int main() {
    for (int i = 1; i <= n; i++) {
        heap[i] = arr[i - 1];
    }
    heapSort(heap, n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", heap[i]);
    }
    return 0;
}