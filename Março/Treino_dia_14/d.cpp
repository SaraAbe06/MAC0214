#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l,r,d,u;

const ll maxn=1e6+2;

ll tanox(ll val){
    if(l<=val and val<=r){
        return 1;
    }
    else return 0;
}

ll tanoy(ll val){
    if(d<=val and val<=u){
        return 1;
    }
    else return 0;
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>l>>r>>d>>u;

    ll tot=0;
    if(l<=0 and 0<=r and d<=0 and 0<=u)tot++;
    for(ll i=2;i<=maxn;i+=2){

        ll v=0;
        if(tanoy(i)){
            ll x,y;
            x=max(-i,l);
            y=min(i,r);

            ll vv=0;
            if(x<=y)vv=(y-x+1);

            tot+=vv;
            v+=(y-x+1);
        }
        if(tanoy(-i)){
            ll x,y;
            x=max(-i,l);
            y=min(i,r);

            ll vv=0;
            if(x<=y)vv=(y-x+1);

            tot+=vv;
             v+=(y-x+1);

        }
         if(tanox(i)){
            ll x,y;
            x=max(-i,d);
            y=min(i,u);

             ll vv=0;
            if(x<=y)vv=(y-x+1);

            tot+=vv;
             v+=(y-x+1);
        }
        if(tanox(-i)){
            ll x,y;
            x=max(-i,d);
            y=min(i,u);

             ll vv=0;
            if(x<=y)vv=(y-x+1);

            tot+=vv;
             v+=(y-x+1);

        }

        if(tanox(i)==1 and tanoy(i)==1)tot--;
        if(tanox(-i)==1 and tanoy(i)==1)tot--;
        if(tanox(i)==1 and tanoy(-i)==1)tot--;
        if(tanox(-i)==1 and tanoy(-i)==1)tot--;

        //cout<<i<<" "<<v<<endl;
    }

    cout<<tot<<'\n';
}