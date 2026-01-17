#include<bits/stdc++.h>
using namespace std;

bool check(string &s ,int i,int j){
	if(i>j){
		return true;
	}
	
	if(s[i]==s[j]){
		return check(s,i+1,j-1);
	}
	return false;
}
int main(){
	string s;
	cin>>s;
	if(check(s,0,s.size()-1)){
		cout<<"yes"<<endl;
	}
	else {
		cout<<"no"<<endl;
	}
}