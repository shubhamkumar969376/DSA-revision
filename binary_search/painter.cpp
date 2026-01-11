#include<bits/stdc++.h> 
using namespace std;
bool check(int x, int k, int arr[], int n) {
    int painter = 1;
    int val = x;

    for (int i = 0; i < n; i++) {
        if (arr[i] > x) return false;

        if (arr[i] > val) {
            painter++;
            val = x - arr[i];
        } else {
            val -= arr[i];
        }
    }
    return painter <= k;
}
int main() {
    int n = 4;
    int k = 2;
    int arr[] = {1, 6, 8, 9};

    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];

    int l = *max_element(arr, arr + n);
    int h = sum;
    int ans = sum;

    while (l <= h) {
        int mid = (l + h) / 2;
        if (check(mid, k, arr, n)) {
            ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;
}

