#include <iostream>
using namespace std;

void Swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int Partition(int* array, int beg, int end) {
    int pivot = array[end];
    int slow = beg - 1;
    int fast = beg;
    while (fast < end) {
        if (array[fast] < pivot) {
            slow = slow + 1;
            Swap(array[slow], array[fast]);
        }
        fast = fast + 1;
    }
    slow = slow + 1;
    Swap(array[slow], array[end]);
    return slow;
}

void QuickSort(int* array, int beg, int end) {
    if (beg < end) {
        int mid = Partition(array, beg, end);
        QuickSort(array, beg, mid - 1);
        QuickSort(array, mid + 1, end);
    }
}

int main() {
    int arr1[] = {9, 2, 5, 3, 7, 1, 0, 4, 8, 6};
    QuickSort(arr1, 0, 9);
    for (int idx = 0; idx < 10; ++idx) {
        cout << arr1[idx] << " ";
    }
    cout << "\n";
    return 0;
}
