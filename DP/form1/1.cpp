//knapsack with time and item constraints
#include<bits/stdc++.h>
using namespace std;

int dp[1010][1010][110];
int n,k,x;
int s[1010];
int t[1010];

int rec(int level,int timetaken,int itemtaken){
    if(level==n || itemtaken==k || timetaken==x){
        return 0;
    }

    if(dp[level][timetaken][itemtaken]!=-1){
        return dp[level][timetaken][itemtaken];
    }

    int ans = rec(level+1, timetaken, itemtaken);

    if(timetaken + t[level] <= x && itemtaken + 1 <= k){
        ans = max(ans,
                  s[level] + rec(level+1,
                                 timetaken + t[level],
                                 itemtaken + 1));
    }

    return dp[level][timetaken][itemtaken] = ans;
}

int main(){
    memset(dp, -1, sizeof(dp));

    cin >> n >> k >> x;
    for(int i=0;i<n;i++) cin >> t[i];
    for(int i=0;i<n;i++) cin >> s[i];

    int ans = rec(0,0,0);
    cout << ans;
}
