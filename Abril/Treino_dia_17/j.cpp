#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=1e6+10;
ll seg[4*maxn];
ll b[maxn];

ll build(ll node,ll l,ll r){
    if(l==r){
        return seg[node]=b[l];
    }
    ll mid=(l+r)/2;
    return seg[node]=build(2*node,l,mid)^build(2*node+1,mid+1,r);
}

ll query(ll node, ll l,ll r,ll a,ll b){
    if(r<a or l>b)return 0;
    if(a<=l and r<=b) return seg[node];
    ll mid=(l+r)/2;
    return query(2*node,l,mid,a,b)^query(2*node+1,mid+1,r,a,b);
}

ll update(ll node, ll l,ll r,ll x,ll k){
    if(r<k or l>k)return seg[node];
    if(l==r){
        return seg[node]+=x;
    }

    ll mid=(l+r)/2;
    return seg[node]=update(2*node,l,mid,x,k)^update(2*node+1,mid+1,r,x,k);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll N,q;cin>>N>>q;
    for(int i=1;i<=N;i++)cin>>b[i];
    build(1,1,N);
    while(q--){
        char s;
        ll a,b;
        cin>>s>>a>>b;
        if(s=='P'){
            if(query(1,1,N,a,b)==0)cout<<"JUAN"<<'\n';
            else cout<<"FRANK"<<'\n';
        }
        else{
            update(1,1,N,b,a);
        }
    }

}
