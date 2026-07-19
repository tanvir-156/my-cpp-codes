
#include <bits/stdc++.h>
using namespace std;

// Merge function to combine two sorted halves
void merge(int arr[], int left, int mid, int right) {
    int left_elements = mid - left + 1;
    int right_elements = right - mid;

    int *L = new int[left_elements];
    int *R = new int[right_elements];

    for (int i = 0; i < left_elements; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < right_elements; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < left_elements && j < right_elements) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < left_elements)
        arr[k++] = L[i++];
    while (j < right_elements)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

// Recursive function to divide array
void divide(int arr[], int left, int right) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    divide(arr, left, mid);
    divide(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    divide(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
