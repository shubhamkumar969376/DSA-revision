#include <bits/stdc++.h>
using namespace std;

int q[20];
int n;

bool check(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (q[i] == col || abs(row - i) == abs(q[i] - col)) {
            return false;
        }
    }
    return true;
}

int Nqueen(int level) {
    if (level == n) {
        return 1; // one valid arrangement
    }

    int count = 0;
    for (int col = 0; col < n; col++) {
        if (check(level, col)) {
            q[level] = col;
            count += Nqueen(level + 1);
        }
    }
    return count;
}

int main() {
   // cin >> n;
   n=4;
    cout << Nqueen(0) << endl;
}
