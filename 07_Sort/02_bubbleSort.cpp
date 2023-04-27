/**
 * 冒泡排序
*/
#include <iostream>

using namespace std;

int arr[] = {3, 1, 5, 7, 2, 4, 9, 6, 10, 8};
int num = 10;

void bubbleSort(int arr[], int len) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) { // 相邻元素两两对比
                temp = arr[j + 1]; // 元素交换
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    bubbleSort(arr, num);
    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}