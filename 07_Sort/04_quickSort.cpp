/**
 * 快速排序
*/
#include <iostream>

using namespace std;

int arr[] = {3, 1, 5, 7, 2, 4, 9, 6, 10, 8};
int num = 10;

void quickSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    // 划分
    int i = left, j = right, pivot = arr[left]; // 取最左边的数为中枢
    while (i < j) {
        while (i < j && arr[j] >= pivot) {
            j--;
        }
        arr[i] = arr[j];
        while (i < j && arr[i] <= pivot) {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    
    // 递归
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

int main() {
    quickSort(arr, 0, num - 1);
    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}