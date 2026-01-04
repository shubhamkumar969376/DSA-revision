#include<bits/stdc++.h>
using namespace std;
string t;
void func(string s){
    if(s.size()==0){
        return;
    }
    t+=s.back();
    s.pop_back();
    func(s);
}

int main(){
    string s="hello";
    func(s);        
    cout<<t;
}