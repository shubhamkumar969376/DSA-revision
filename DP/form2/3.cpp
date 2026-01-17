#include<bits/stdc++.h>
using namespace std;
int n;
int nums[100][100];
int dp[1000][1000];
int rec(int i,int j){
	if(i>=n || j>=n || i<0 || j<0){
		return -1e9;
	}
	
	
	if(i==n-1 && j==n-1){
		return nums[i][j];
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	
	int ans=max(rec(i+1,j)+nums[i][j],rec(i,j+1)+nums[i][j]);
	return dp[i][j]=ans;
	
	
	
}
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>nums[i][j];
		}
	}
	int ans=rec(0,0);
	cout<<ans<<endl;
	
}