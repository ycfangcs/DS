/**
 * 插入排序
*/
#include <iostream>

using namespace std;

int arr[] = {3, 1, 5, 7, 2, 4, 9, 6, 10, 8};
int num = 10;

void insertSort(int arr[], int len) {
    int i, j, temp;
    for (i = 1; i < len; i++) {
        temp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > temp; j--)
        {
            arr[j + 1] = arr[j]; // 将大于temp的值整体后移一个单位
        }
        arr[j + 1] = temp; // 插入到合适的位置
    }
}

int main() {
    insertSort(arr, num);
    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}