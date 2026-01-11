// dfs all concept


#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g;
vector<int>vis;
void dfs(int node,vector<int>&nums,int cnt){
	vis[node]=cnt;
	for(auto i:g[node]){
		if(!vis[i]){
			dfs(i,nums,cnt);
		}
	}
	nums.push_back(node);
}
int main(){
	int n,m;
	cin>>n>>m;
	g.resize(n+1);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[a].push_back(b);
	}
	vis.assign(n+1,0);
	int cnt=0;// for connected componenet
	//for size of componenets
	vector<vector<int>>ans;
	
	for(int i=1;i<=n;i++){
		vector<int>st;
		if(!vis[i]){
			 cnt++;
			dfs(i,st,cnt);
			ans.push_back(st);
		}
		
	}
	for(int i=1;i<=n;i++){
		cout<<vis[i]<<endl;
	}
	cout<<cnt<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].size()<<"size of componet "<<i+1<<endl;
	}
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		
		if(vis[a]==vis[b]){
			cout<<"all belong to same commpnenets "<<endl;
			
		}
		else {
			cout<<" they belongs to differnt componenets"<<endl;
		}
	}
	
}