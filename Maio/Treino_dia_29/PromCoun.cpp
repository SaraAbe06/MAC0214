//ac
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

template <class T>
    using ord_set = tree<T,null_type,less<T>,rb_tree_tag, tree_order_statistics_node_update>;

ll p[100010];
vector<ll>adj[100010];
ll res[100010];


ord_set<ll>* dfs(ll u,ll pai){
    
   // cerr<<"0\n";
    auto *m = new ord_set<ll>();
    m->insert(p[u]);

    for(auto vv:adj[u]){
        if(vv==pai)continue;

        ord_set<ll>* aux=dfs(vv,u);
        if(aux->size()>m->size())swap(aux,m);
        for(auto a:*aux){
            m->insert(a);
        }
    }

    res[u]= m->size()-1-m->order_of_key(p[u]);
   
    return m;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();

     freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    ll n;cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=2;i<=n;i++){
        ll a;cin>>a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }

    dfs(1,1);

    for(int i=1;i<=n;i++)cout<<res[i]<<'\n';


}
