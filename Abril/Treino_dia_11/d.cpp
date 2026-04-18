#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=1e5+10;
vector<ll> adj[2*maxn];
ll visi[2*maxn],visi2[2*maxn];
vector<ll>aux;
ll ciclo_impar=0,grau=0;
ll alt[2*maxn];

ll mp=0,mi=0;

void dfs(ll v, ll pai, ll tam){
    if(tam%2==0)mp++;
    else mi++;

    visi2[v]=1;
    aux.push_back(v);
    alt[v]=tam;
    if(adj[v].size()>=3)grau=1;

    for(auto p:adj[v]){
        if(visi2[p]==0){
            dfs(p,v,tam+1);
        }
        else if(p!=pai){
            if((tam-alt[p]+1)%2==1)ciclo_impar=1;
        }
    }
}


int main(){
    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        for(int i=1;i<=n;i++){
            adj[i].clear();
            visi[i]=0;
            visi2[i]=0;
        }

        for(int i=0;i<m;i++){
            ll a,b;cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        ll tot=0;

        for(int i=1;i<=n;i++){
            if(visi[i]==0){
                dfs(i,i,0);

                //for(auto p:aux){
                  //  cout<<p<<" ";
                //}

                //cout<<"a:"<<ciclo_impar<<" "<<grau<<endl;
                // ve se tem ciclo impar, se sim, marco visi2 pro visi e vou pro proximo 
                if(ciclo_impar){
                    for(int i=0;i<aux.size();i++)visi[aux[i]]=1;
                    mp=0,mi=0;
                    ciclo_impar=0;
                    aux.clear();
                    continue;
                }
                // cc, anoto a qtd de vertices, marco visi2 pro visi e vou pro proximo 
                else{
                    for(int i=0;i<aux.size();i++)visi[aux[i]]=1;
                    ciclo_impar=0;
                    tot+=max(mi,mp);
                    mp=0,mi=0;
                    aux.clear();
                    continue;
                }
              
            }
        }

        cout<<tot<<'\n';
    }
}