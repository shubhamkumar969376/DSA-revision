#include<bits/stdc++.h>
using namespace std;
int sum;
void func(int n){
    if(n==0){
        return;
    }
    func(n-1);
    sum+=n;

}

int main(){
    int n=7;
    func(n);
    cout<<sum/n;
}