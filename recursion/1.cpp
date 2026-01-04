#include<bits/stdc++.h>
using namespace std;
void func(int n){
    if(n==0){
        return;
    }
    func(n-1);
    cout<<(n)<<endl;

}

int main(){
    int n=7;
    func(n);
}