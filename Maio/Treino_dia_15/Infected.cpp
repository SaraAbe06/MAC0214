//ac
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=1e5+10;
const ll mod=1e9+7;

vector<ll>adj[3*maxn];
ll dp[3*maxn];
ll nos[3*maxn];

void dfs(ll u,ll pai){
    dp[u]=0;
    nos[u]=1;

    for(auto v:adj[u]){
        if(v!=pai){
            dfs(v,u);
            nos[u]+=nos[v];
        }
    }

    int c1=-1,c2=-1;

    for(auto v:adj[u]){
        if(v!=pai){
            if(c1==-1){
                c1=v;
            }
            else{
                c2=v;
            }
        }
    }

    if(c1==-1){
        return;
    }
    else{
        if(c2==-1){
            dp[u]=nos[c1]-1;
        }
        else{
            dp[u]=max(dp[c1]+nos[c2]-1,dp[c2]+nos[c1]-1);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        for(int i=0;i<=n;i++){
            adj[i].clear();
            dp[i]=-1;
        }

        for(int i=0;i<n-1;i++){
            ll a,b;cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(1,1);

        cout<<dp[1]<<'\n';

    }

}