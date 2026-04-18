//wa no 76 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> par;

const ll inf=1e16;

struct Quad{
    ll xm,xM;
    ll ym,yM;

    ll g;
};

int ta_meio(Quad a, ll x, ll y){
    if( (a.xm <= x) and(x <= a.xM) and (a.ym<=y) and (y<=a.yM)){
        return 1;
    }
    return 0;
}

int colide(Quad a, Quad b){
    if(ta_meio(a,b.xm,b.ym) or ta_meio(a,b.xm,b.yM) or 
    ta_meio(a,b.xM,b.ym) or ta_meio(a,b.xM,b.yM) or 
    ta_meio(b,a.xm,a.ym) or ta_meio(b,a.xm,a.yM) or 
    ta_meio(b,a.xM,a.ym) or ta_meio(b,a.xM,a.yM) ){
        return 1;
    }

    return 0;
}

vector<Quad> meus_quad;
vector<ll> adj[1010];

priority_queue<par,vector<par>,greater<par>>pq;

ll indC,indB,indE,indD;
ll visi[1010];
ll dist[1010];

void dijkstra(ll s){
    for(int i=0;i<1010;i++)visi[i]=0;
    for(int i=0;i<1010;i++)dist[i]=inf;

    pq.push({0,s});
    dist[s]=0;

    while(!pq.empty()){
        auto [peso, v]=pq.top();
        pq.pop();

        if(visi[v])continue;
        visi[v]=1;

        for(auto p:adj[v]){
            if(dist[p]>peso+meus_quad[p].g){
                pq.push({peso+meus_quad[p].g, p});
                dist[p]=peso+meus_quad[p].g;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    //subtrair 1 da menor coordenada 

    ll N,M,K;cin>>N>>M>>K;
    for(int i=0;i<K;i++){
        ll a,b,c,d,g;cin>>a>>b>>c>>d>>g;
        Quad aux={a-1,c,b-1,d,g};
        meus_quad.push_back(aux);
    }

    for(int i=0;i<K;i++){
        for(int j=i+1;j<K;j++){
            if(colide(meus_quad[i],meus_quad[j])){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    indC=K, indB=K+1, indE=K+2,indD=K+3;

    for(int i=0;i<K;i++){
        // indC
        if(meus_quad[i].xm==0){
            adj[indC].push_back(i);
        }

        if(meus_quad[i].xM==N){
            adj[i].push_back(indB);
           
        }

        if(meus_quad[i].ym==0){
            adj[i].push_back(indE);
            
        }

        if(meus_quad[i].yM==M){
            adj[indD].push_back(i);
        }


    }
    for(int i = 0; i < 4; i++) {
        Quad tmp = {0, 0, 0, 0, 0};
        meus_quad.push_back(tmp);
    }

    ll resp=inf;
    dijkstra(indC);
    resp=min(dist[indB],dist[indE]);
    dijkstra(indD);
    resp=min(resp,min(dist[indB],dist[indE]));

    if(resp==inf) resp=-1;
    cout<<resp<<'\n';

  
}