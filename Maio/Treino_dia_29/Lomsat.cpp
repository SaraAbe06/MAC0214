//ac
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c[100010];
vector<ll>adj[100010];
ll somas[100010];

struct node{
    map<ll,ll>mapa;
    ll maior;
    ll tot;
};

node dfs(ll u,ll pai){
    node agr;
    
    agr.mapa[c[u]]++;
    agr.maior=1;
    agr.tot=c[u];

    for(auto p:adj[u]){
        if(p==pai)continue;

        node aux=dfs(p,u);
        ll flag=0;
        ll mudou=0;

        if(aux.mapa.size()>agr.mapa.size()){swap(agr,aux);}

        for(auto [a,b]:aux.mapa){
            ll bf=agr.mapa[a];
            agr.mapa[a]+=b;
            ll atual=agr.mapa[a];

            if(atual>agr.maior){
                mudou=1;
                agr.maior=atual;
                agr.tot=a;
            }
            else if(atual==agr.maior){
                if(bf!=agr.maior)agr.tot+=a;
            }

            //if(mudou==0 and flag==1)tot-=a;
        }

      //  if(mudou==0 and flag==1)tot+=somas[p];
    }

    //if(m[c[u]]==maior and maior==1)tot+=c[u];
    
    somas[u]=agr.tot;
    return agr;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();

    ll n;cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=0;i<n-1;i++){
        ll a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,1);

    for(int i=1;i<=n;i++)cout<<somas[i]<<' ';


}
