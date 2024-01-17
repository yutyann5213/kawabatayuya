#include <stdio.h>

// 挿入ソート関数
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // keyより大きい要素を後ろにずらす
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// 配列を表示する関数
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // ソート前の配列
    int arr[] = {1, 9, 3, 2, 5, 7, 4, 6, 8, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before: ");
    printArray(arr, n);

    // 挿入ソートを実行
    insertionSort(arr, n);

    printf("After: ");
    printArray(arr, n);

    return 0;
}