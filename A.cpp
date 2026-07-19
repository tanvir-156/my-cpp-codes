#include <iostream>
using namespace std;

int main() {
    int n, setNum = 1;
    while (cin >> n && n != 0) {
        int h[50], sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> h[i];
            sum += h[i];
        }

        int avg = sum / n;
        int moves = 0;
        for (int i = 0; i < n; i++) {
            if (h[i] > avg) {
                moves += (h[i] - avg);
            }
        }

        cout << "Set #" << setNum++ << "\n";
        cout << "The minimum number of moves is " << moves << ".\n\n";
    }
    return 0;
}

