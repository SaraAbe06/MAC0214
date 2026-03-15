#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=1e5+10;

vector<ll> adj[2*maxn];
ll n;
ll pesos[2*maxn];

ll qtd=1;
set<ll>vp;

ll visi[2*maxn];
ll info[2*maxn];

void dfs(int u){
    visi[u]=1;

    for(auto p:adj[u]){
        if(!visi[p]){
            ll flag=0;
            ll antes=vp.size();

            vp.insert(pesos[p]);
            qtd++;
            if(vp.size()!=qtd)info[p]=1;
            else flag=1;

            dfs(p);

            if(antes!=vp.size())vp.erase(pesos[p]);
            qtd--;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>pesos[i];

    for(int i=1;i<=n-1;i++){
        ll u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vp.insert(pesos[1]);
    dfs(1);

    cout<<"No"<<endl;
    for(int i=2;i<=n;i++){
        if(info[i]==1)cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
    }


}
