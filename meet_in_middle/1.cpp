// MeetInTheMiddle.cpp
// count(vector<ll>, int)




#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> generateAllSumOfSubsets(vector<int> arr) {
    int n = arr.size();
    vector<ll> subVals;

    for (ll mask = 0; mask < (1LL << n); mask++) {
        ll sum = 0;
        for (ll j = 0; j < n; j++) {
            if ((mask >> j) & 1) {
                sum += arr[j];
            }
        }
        subVals.push_back(sum);
    }

    sort(subVals.begin(), subVals.end());
    return subVals;
}

ll count(vector<ll> arr, int x) {
    ll ans = 0;

    vector<int> newArr[2];
    for (int i = 0; i < arr.size(); i++) {
        newArr[i & 1].push_back(arr[i]);
    }

    vector<ll> sub0 = generateAllSumOfSubsets(newArr[0]);
    vector<ll> sub1 = generateAllSumOfSubsets(newArr[1]);

    for (auto v : sub0) {
        ans += upper_bound(sub1.begin(), sub1.end(), x - v) - sub1.begin();
    }

    return ans;
}



// time complexity: O(2^(n/2) * log(2^(n/2))) = O((n/2) * 2^(n/2)) = O(n * 2^(n/2))
// space complexity: O(2^(n/2))