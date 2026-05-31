//Estava tentando resolver ele, mas não obtive sucesso
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>par;

ll c[10010];
vector<ll>adj[10010];

vector<par>extras[10010];
map<par,ll>mapa;

ll res[10010];

map<par,ll>ids;

multiset<ll> dfs(ll u,ll pai){
    cout<<"AAAA:"<<u<<endl;
    multiset<ll>m;

    for(auto p:adj[u]){
        if(p==pai)continue;

        cout<<"filho:"<<p<<endl;
        multiset<ll>aux=dfs(p,u);
        if(aux.empty())continue;

        ll menor=*aux.begin();
        ll id=ids[{u,p}];
        res[id]=menor;

        if(aux.size()>m.size())swap(m,aux);

        for(auto elem:aux){
            m.insert(elem);
        }


        cout<<"AQUI:"<<u<<endl;
        for(auto [elem,peso]:extras[p]){
            ll id=mapa[{p,elem}];
            cout<<"infos:"<<id<<" "<<p<<" "<<elem<<" "<<c[id]<<endl;

            if(c[id]==2)m.erase(m.find(peso));
        }

    }

    cout<<"here"<<endl;

    for(auto [elem,peso]:extras[u]){
        ll id=mapa[{u,elem}];
        cout<<id<<" "<<u<<" "<<elem<<endl;
        c[id]++;
        m.insert(peso);
    }

    cout<<"to em:"<<u<<endl;
    for(auto p:m){
        cout<<p<<" ";
    }
    cout<<endl;

    return m;
}

ll raiz=-1;

int main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();

    ll n,m;cin>>n>>m;
    for(int i=1;i<=n-1;i++){
        ll a,b;cin>>a>>b;
        if(raiz==-1)raiz=a;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ids[{a,b}]=i;
        ids[{b,a}]=i;
        res[i]=-1;
    }

    for(int i=1;i<=m;i++){
        ll a,b,w;cin>>a>>b>>w;
        mapa[{a,b}]=i;
        mapa[{b,a}]=i;
        extras[a].push_back({b,w});
        extras[b].push_back({a,w});
    }

    dfs(raiz,raiz);

    for(int i=1;i<=n-1;i++)cout<<res[i]<<'\n';
    
}
