#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll t;cin>>t;
    while(t--){
        ll a,b;cin>>a>>b;
        ll val=b/a;
        if(val!=2 and a!=b-1){
            ll v2=(val-1)*a;
            if(v2>a and v2<b)cout<<"YES\n";
            else cout<<"NO\n";
        }
        else cout<<"NO\n";
    }
}
