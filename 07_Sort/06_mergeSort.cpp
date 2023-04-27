/**
 * 归并排序
*/
#include <iostream>

using namespace std;

int arr[] = {3, 1, 5, 7, 2, 4, 9, 6, 10, 8};
int num = 10;

void merge(int arr[], int left, int mid, int right) {
    int len = right - left + 1;
    int *temp = new int[len]; // 辅助数组
    int index = 0;
    int i = left;
    int j = mid + 1;
    while (i <= mid && j <= right) {
        temp[index++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    }
    while (i <= mid) {
        temp[index++] = arr[i++];
    }
    while (j <= right) {
        temp[index++] = arr[j++];
    }
    for (int k = 0; k < len; k++) {
        arr[left++] = temp[k];
    }
    delete[] temp;
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) >> 1;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    mergeSort(arr, 0, num - 1);
    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}