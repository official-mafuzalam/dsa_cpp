#include <iostream>
#include <stack>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortIterative(int arr[], int n) {
    stack<int> stk;

    stk.push(0);
    stk.push(n - 1);

    while (!stk.empty()) {
        int high = stk.top();
        stk.pop();
        int low = stk.top();
        stk.pop();

        int p = partition(arr, low, high);

        if (p - 1 > low) {
            stk.push(low);
            stk.push(p - 1);
        }

        if (p + 1 < high) {
            stk.push(p + 1);
            stk.push(high);
        }
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSortIterative(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
