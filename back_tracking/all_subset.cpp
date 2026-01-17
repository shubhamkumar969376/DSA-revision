#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>ans;
int n;
int cnt;

void generate(int level,vector<int>&arr,vector<int>&st){
	if(level==n){
		cnt++;
		ans.push_back(st);
		return;
	}
	generate(level+1,arr,st);
	st.push_back(arr[level]);
	generate(level+1,arr,st);
	st.pop_back();
}
int main(){
	
	vector<int>arr={1,2,3,4};
	n=arr.size();
	vector<int>st;
	generate(0,arr,st);
	for(auto i:ans){
		cout<<"{ ";
		for(auto v:i ){
			cout<<v<<" ";
		}
		cout<<"}";
		cout<<endl;
	}
	cout<<cnt<<endl;
}