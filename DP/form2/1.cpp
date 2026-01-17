#include<bits/stdc++.h>
using namespace std;

int dp[101010];
int arr[10101];

int rec(int level){
    if(level == 0){
        return dp[level] = 1;
    }

    if(dp[level] != -1){
        return dp[level];
    }

    int ans = 1;
    for(int i = 0; i < level; i++){
        if(arr[level] > arr[i]){
            ans = max(ans, 1 + rec(i));
        }
    }
    return dp[level] = ans;
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, rec(i));
    }

    cout << ans << endl;
}
