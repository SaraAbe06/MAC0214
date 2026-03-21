#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=1e5+10;

ll psum4[2*maxn];
ll psum8[2*maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll n,q;cin>>n>>q;
    string s;cin>>s;

    for(int i=0;i<n;i++){
        if(s[i]=='4'){
            psum8[i+1]=psum8[i];
            psum4[i+1]=psum4[i]+1;
        }
        else{
            psum4[i+1]=psum4[i];
            psum8[i+1]=1+psum8[i];
        }
    }

    while(q--){
        ll l,r,x,y;cin>>l>>r>>x>>y;

        ll a=psum8[r]-psum8[l-1];
        ll b=psum4[r]-psum4[l-1];

        if(x==0 and y==0){
            cout<<"YES"<<'\n';
        }
        else if(abs(x)<=a and abs(y)<=a){
            cout<<"YES"<<'\n';
        }
        else{
            ll dist=0;
            if(abs(x)>a) dist+=abs(abs(x)-a);
            if(abs(y)>a)dist+=(abs(y)-a);

            if(dist<=b)cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }

}
