#include<stdio.h>
#include<stdlib.h>

#define DATA_SIZE 100
#define TARGET 50

// 乱数を生成して配列に格納
void generateRandomData(int data[], int size) {
    for (int i = 0; i < size; ++i) {
        data[i] = rand() % 101; // 0から100までの乱数
    }
}

// 配列を昇順にソート
void sortData(int data[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                // 要素を交換
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

// 二分探索でターゲットを検索
int binarySearch(int data[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (data[mid] == target) {
            result = mid;
            break;
        } else if (data[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    int data[DATA_SIZE];
    generateRandomData(data, DATA_SIZE);

    // 配列を表示（デバッグ用）
    printf("Array: ");
    for (int i = 0; i < DATA_SIZE; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // 配列をソート
    sortData(data, DATA_SIZE);

    // ソート後の配列を表示（デバッグ用）
    printf("Array after sorting: ");
    for (int i = 0; i < DATA_SIZE; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // 二分探索でターゲットを検索
    int result = binarySearch(data, DATA_SIZE, TARGET);

    // 結果の出力
    if (result >= 0) {
        printf("Target %d is at index %d in array\n", TARGET, result);
    } else {
        printf("Target %d was not found in the array\n", TARGET);
    }

    return 0;
}