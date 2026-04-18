#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>par;

par v[5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;cin>>t;
    while(t--){
        for(int i=0;i<4;i++){
            ll a;cin>>a;
            ll s=1;
            if(i>=2)s=2;
            v[i]={a,s};
        }
        sort(v,v+4);

        if(v[0].second==v[1].second) cout<<"0"<<'\n';
        else{
           
            cout<<v[2].first-v[1].first<<'\n';
           
        }
    }
}
