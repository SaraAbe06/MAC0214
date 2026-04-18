#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>par;

const ll maxn=1e5+10;
ll v[2*maxn];
par m[2*maxn]; 

int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll maior=0,ind=0;
        for(int i=1;i<=n;i++){
            cin>>v[i];

            if(i==1){
                maior=v[i];
                ind=1;

                m[i]={maior,ind};
            }
            else{
                if(v[i]>=maior){
                    maior=v[i];
                    ind=i;
                    m[i]={maior,ind};
                }
                else{
                    m[i]={maior,ind};
                }
            }
        }

        ind=n;
        ll tot=0;
        while(ind>=1){
            ll a=m[ind].second;
            tot++;
            ind=a-1;
        }

        cout<<tot<<'\n';

        
    }
}