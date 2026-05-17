//ac
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=1e5+10;
vector<ll>adj[2*maxn];
int visi[2*maxn];
int dp1[2*maxn];
int dp2[2*maxn];

void dfs(ll u,ll pai){
    int qtd=0;
    visi[u]=1;

    //calcula dp2 
    for(auto v:adj[u]){
        if(v!=pai){
            dfs(v,u);
            dp2[u]+=max(dp1[v],dp2[v]);
        }
    }

    //calcula dp1
    for(auto v:adj[u]){
        if(v!=pai){
            dp1[u]=max(dp1[u],dp2[v]+1+dp2[u]-max(dp1[v],dp2[v]));
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n;cin>>n;
    for(int i=0;i<n-1;i++){
        ll a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,1);
    cout<<max(dp1[1],dp2[1])<<'\n';

}