//ac
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=1e5+10;
const ll mod=1e9+7;

vector<ll>adj[2*maxn];
ll dp1[maxn],dp2[maxn];

ll soma(ll a,ll b){
    return (a+b)%mod;
}

ll mult(ll a,ll b){
    return 1ll*(a*b)%mod;
}

void dfs(ll u,ll pai){
    int qtd=0;
    dp1[u]=1;
    dp2[u]=1;

    for(auto v:adj[u]){
        if(v!=pai){
            qtd++;
            dfs(v,u);

            dp2[u]=mult(dp2[u],dp1[v]); //preto
            dp1[u]=mult(soma(dp1[v],dp2[v]),dp1[u]);
           
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
    cout<<soma(dp1[1],dp2[1])<<'\n';

}