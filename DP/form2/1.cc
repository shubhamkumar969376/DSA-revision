
// longest increse subsequence through form one ........

#include<bits/stdc++.h>
using namespace std ;
vector<int>arr;
int n;
int dp[1000][10000];
int rec(int l,int val){
	if(l==n){
		return 0;
	}
	if(dp[l][val]!=-1){
		return dp[l][val];
	}
	int ans=rec(l+1,val);
	
	if(val<arr[l]){
		ans=max(ans,1+rec(l+1,arr[l]));
	}
	
	return dp[l][val]=ans;
}
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n;
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ans=rec(0,0);
	cout<<ans<<endl;
}