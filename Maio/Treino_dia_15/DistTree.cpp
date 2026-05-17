//ac
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=1e4+10;

vector<ll>adj[5*maxn];
ll mat[5*maxn][510];
ll k;
ll tot=0;

void dfs(ll u,ll pai){
    mat[u][0]=1;

    for(auto v:adj[u]){
        if(v!=pai){
            dfs(v,u);

            for(int i=0;i<k;i++){
                tot+=mat[u][i]*mat[v][k-i-1];
            }

            for(int i=0;i<=k;i++){
                mat[u][i+1]+=mat[v][i];
            }
            
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n;cin>>n>>k;
    int ini=0;
    for(int i=0;i<n-1;i++){
        ll a,b;cin>>a>>b;
        ini=a;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(ini,ini);
    cout<<tot<<'\n';

}
