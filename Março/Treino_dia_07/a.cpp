#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll n,x;cin>>n>>x;
    for(int i=0;i<n;i++){
        ll a;cin>>a;
        if(a<x){
            x=a;
            cout<<1<<'\n';
        }
        else{
            cout<<0<<'\n';
        }
    }
}
