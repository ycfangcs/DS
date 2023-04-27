/**
 * 快速排序的扩展
 * 1. 另一种快速排序写法
 * 2. 快速选择算法
*/
#include <iostream>

using namespace std;

int arr[] = {3, 1, 5, 7, 2, 4, 9, 6, 10, 8};
int num = 10;

// 交换数组中两个元素的位置
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// 一次划分
int partition(int arr[], int left, int right) {
    int pivot = arr[right]; // 取最后一个元素作为基准
    int tail = left - 1; // tail为小于基准的子数组最后一个元素的索引
    for (int i = left; i < right; i++) { // 遍历基准以外的其他元素
        if (arr[i] <= pivot) { // 把小于等于基准的元素放到前一个子数组末尾
            swap(arr, ++tail, i);
        }
    }
    swap(arr, tail + 1, right); // 最后把基准放到前一个子数组的后边，剩下的子数组即为大于基准的子数组
    return tail + 1; // 返回基准的索引
}

// 递归实现快速排序
void quickSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot_index = partition(arr, left, right); // 基准的索引
    quickSort(arr, left, pivot_index - 1);
    quickSort(arr, pivot_index + 1, right);
}

// 快速选择算法
int quickSelect(int arr[], int left, int right, int k) {
    int pivot_index = partition(arr, left, right);
    if (pivot_index == k - 1) {
        return arr[pivot_index];
    } else if (pivot_index > k - 1) {
        return quickSelect(arr, left, pivot_index - 1, k);
    } else {
        return quickSelect(arr, pivot_index + 1, right, k);
    }
}

int main() {
    quickSort(arr, 0, num - 1);
    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "第4小的数是：";
    cout << quickSelect(arr, 0, num - 1, 4) << endl;
    return 0;
}