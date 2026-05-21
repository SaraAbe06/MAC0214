#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=200005;

ll seg[4*maxn];
vector<ll>adj[maxn];
ll v[maxn];
ll comeco[maxn];
ll fim[maxn];
ll aux[maxn];
ll tempo=0;

void eulerTour(ll u,ll pai){
    comeco[u]=++tempo;
    for(auto p:adj[u]){
        if(p!=pai){
            eulerTour(p,u);
        }
    }
    fim[u]=tempo;
}

ll build(ll node, ll l,ll r){
    if(l==r){
        return seg[node]=aux[l];
    }

    ll mid=(l+r)/2;
    return seg[node]=build(2*node,l,mid)+build(2*node+1,mid+1,r);
}

ll update(ll node, ll l, ll r, ll x, ll val){
    if(r<x or l>x)return seg[node];
    if(l==r and l==x){
        return seg[node]+=val;
    }

    ll mid=(l+r)/2;
    return seg[node]=update(2*node,l,mid,x,val)+update(2*node+1,mid+1,r,x,val);

}

ll query(ll node, ll l, ll r, ll a, ll b){
    if(l>b or r<a)return 0;
    if(a<=l and r<=b)return seg[node];
    ll mid=(l+r)/2;
    return query(2*node,l,mid,a,b)+query(2*node+1,mid+1,r,a,b);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=n-1;i++){
        ll a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    eulerTour(1,1);
    for(int i=1;i<=n;i++){
        aux[comeco[i]]+=v[i];
        aux[fim[i]+1]-=v[i];
    }

    build(1,1,n+1);

    while(q--){
        ll c;cin>>c;
        if(c==1){
            ll s,x;cin>>s>>x;
            ll dif=x-v[s];
            update(1,1,n+1,comeco[s],dif);
            update(1,1,n+1,fim[s]+1,-dif);
            v[s]=x;
        }
        else{
            ll x;cin>>x;
            cout<<query(1,1,n+1,1,comeco[x])<<'\n';

        }
    }

}
