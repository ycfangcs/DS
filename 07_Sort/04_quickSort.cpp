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
    int i = left, j = right, temp = arr[left]; // 取最左边的数为基准数
    while (i < j) {
        while (i < j && arr[j] >= temp) {
            j--;
        }
        arr[i] = arr[j];
        while (i < j && arr[i] <= temp) {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = temp;
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