#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=998244353;

ll soma(ll a,ll b){
    return (a+b)%mod;
}

ll mult(ll a, ll b){
    return (ll)((__int128)a*b)%mod;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll t;cin>>t;
    while(t--){
        ll n,x;cin>>n>>x;
        ll v1=0,v3=0;
        ll y1=0,y3=0;
        ll aux=n/4;
        ll res=n%4;

        v3++;
        if(n>=3)v3=soma(v3,(1+(n-3)/4)%mod);
        if(n>=1)v1=soma(v1,(1+(n-1)/4)%mod);
        
     
        if(x-1>=3)y3=soma(y3,(1+(x-1-3)/4)%mod);
        if(x-1>=1)y1=soma(y1,(1+(x-1-1)/4)%mod);
        
        y3++;
       // cout<<"a:"<<v1<<" "<<v3<<" "<<y1<<" "<<y3<<endl;


        res=soma(mult(y1,soma(v1,mod-y1)),mult(y3,soma(v3,mod-y3)));
       // res=soma(res,soma(v3,mod-y3));
        cout<<res<<'\n';

    }
}