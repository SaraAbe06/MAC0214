//Meet in the middle - divide em 2 negocio o problema e passa por tds casos de cada metade 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>v;

vector<ll> geratds(ll l, ll r){
    ll len=r-l+1;
    vector<ll>res;

    for(int i=0;i<(1<<len);i++){
        ll sum=0;
        for(int j=0;j<len;j++){
            if(i & (1<<j))sum+=v[l+j];
        }

        res.push_back(sum);
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n,x;cin>>n>>x;
    for(int i=0;i<n;i++){
        ll a;cin>>a;
        v.push_back(a);
    }

    if(n==1){
        if(v[0]==x)cout<<1<<'\n';
        else cout<<0<<'\n';
        return 0;
    }

    vector<ll>left=geratds(0,n/2-1);
    vector<ll>right=geratds(n/2,n-1);

    sort(left.begin(),left.end());
    sort(right.begin(),right.end());

    ll ans=0;
    for(ll i:left){
        auto low_it=lower_bound(right.begin(),right.end(),x-i);
        auto high_it=upper_bound(right.begin(),right.end(),x-i);

        ans+=(high_it-low_it);
    }

    cout<<ans<<'\n';

}
