#include<bits/stdc++.h>
using namespace std;
int dp[10001][10001];
string s,t;
int n,m;

int rec(int i,int j){
	if(i>=n || j>=m){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	int ans=0;
	ans=rec(i+1,j);
	 ans=rec(i,j+1);
	if(s[i]==t[j]){
		ans=max(ans,1+rec(i+1,j+1));
	}
	return dp[i][j]=ans;
	
}
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>s>>t;
	n=s.size();
	m=t.size();
	
	cout<<rec(0,0);
	
}