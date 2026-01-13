// 1.DECIDE THE FORM
//2.STATE FORMULATION
//3.TRANSITION DESIGN 
//4.TC CHECK
//5.IMPLEMENTATION
// knapsack solutuion with reconstruction
#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int n,X;
int s[100];

int t[101];
int rec(int level,int X){
	if(level==n){
		return 0;
	}
	if(dp[level][X]!=-1){
		return dp[level][X];
	}
	int ans=rec(level+1,X);
	if(t[level]<=X){
		ans=max(ans,s[level]+rec(level+1,X-t[level]));
	}
	return dp[level][X]=ans;
	
}

vector<int>sol;
void generate(int i,int x){
	if(i==n){
		return ;
	}
	int dontake=rec(i+1,x);
	if(t[i]<=x){
		int take=rec(i+1,x-t[i])+s[i];
		
		if(dontake>take){
			generate(i+1,X);
		}
		else{
			sol.push_back(i);
			generate(i+1,x-t[i]);
		}
		
	}
	else{
		generate(i+1,x);
	}
}
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n>>X;
	for(int i=0;i<n;i++){
		cin>>t[i];
	}
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	int ans=rec(0,X);
	cout<<ans<<endl;
	generate(0,X);
	for(auto i: sol){
		cout<<t[i]<<" "<<s[i]<<endl;
	}
}