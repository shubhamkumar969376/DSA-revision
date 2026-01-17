#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> st;

void gen(int open, int close, string s) {
    if (s.size() == (size_t)n) {
        st.push_back(s);
        return;
    }

    if (open < n / 2) {
        gen(open + 1, close, s + '(');
    }

    if (close < open) {
        gen(open, close + 1, s + ')');
    }
}

int main() {
    cin >> n;

    if (n % 2 != 0) return 0;

    gen(0, 0, "");

    for (auto &x : st) {
        cout << x << "\n";
    }
}
