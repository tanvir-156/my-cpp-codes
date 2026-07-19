#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {2, 4, 9, 6, 1, 11, 12, 15};
    int item = 6;
    int left = 0, right = 7; // right should be 7, the last index of the array

    while (left <= right) {
        int middle = left + (right - left) / 2; // Correct formula for middle

        if (a[middle] == item) { // Correct comparison
            cout << "Item found at index " << middle << endl; // Output the index
            return 0;
        } else if (a[middle] < item) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    cout << "Not Found" << endl; // Added missing semicolon
}
