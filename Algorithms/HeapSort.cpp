#include <iostream>
using namespace std;

void Swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void HeapAdjust(int* array, int length, int branch) {
    while (branch < length / 2) {
        int left = 2 * branch + 1;
        int right = 2 * branch + 2;
        int maxChild = left;
        if (right < length && array[right] > array[left]) {
            maxChild = right;
        }
        if (array[branch] < array[maxChild]) {
            Swap(array[branch], array[maxChild]);
        } else {
            break;
        }
        branch = maxChild;
    }
}

void HeapSort(int* array, int length) {
    for (int idx = length / 2 - 1; idx >= 0; --idx) {
        HeapAdjust(array, length, idx);
    }
    for (int idx = length - 1; idx > 0; --idx) {
        Swap(array[0], array[idx]);
        HeapAdjust(array, idx, 0);
    }
}

int main() {
    int arr1[] = {9, 2, 5, 3, 7, 1, 0, 4, 8, 6};
    HeapSort(arr1, 10);
    for (int idx = 0; idx < 10; ++idx) {
        cout << arr1[idx] << " ";
    }
    cout << "\n";
    return 0;
}
