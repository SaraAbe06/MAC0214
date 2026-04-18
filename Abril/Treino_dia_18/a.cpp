#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll t;cin>>t;
    while(t--){
        ll x,y;cin>>x>>y;
        if(y==0){
            if(x%3==0)cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
        else if(y>0){
            ll val=y;
            if(x-2*val>=0 and (x-2*val)%3==0)cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
        else{
            ll val=(-1)*y;
            if(x-4*val>=0 and (x-4*val)%3==0)cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }
}
