#include<bits/stdc++.h>
using namespace std;

int dp[100][101];

int rec(int x, int y){
    // base cases
    if(x == 0 && y == 0) return 0;
    if(x == 0 || y == 0) return 1;

    // cache
    if(dp[x][y] != -1) return dp[x][y];

    int ans = 0;

    // remove from x
    for(int z = 0; z < x; z++){
        if(rec(z, y) == 0){
            ans = 1;
            break;
        }
    }

    // remove from y
    for(int z = 0; z < y && ans == 0; z++){
        if(rec(x, z) == 0){
            ans = 1;
            break;
        }
    }

    // diagonal move (FIXED)
    for(int z = 1; z <= min(x, y) && ans == 0; z++){
        if(rec(x - z, y - z) == 0){
            ans = 1;
            break;
        }
    }

    return dp[x][y] = ans;
}

void solve(){
    int a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    cout << rec(a, b) << endl;
    
}

int main(){
    solve();
}
