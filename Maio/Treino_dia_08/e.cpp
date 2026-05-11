//ac
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> par;

vector<par>v;
stack<par>dps;
map<ll,ll>mapa;
map<ll,ll>nov;
vector<par>fim;
map<par,ll>existe;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n;cin>>n;
    ll tdsy=0,prim=1;
    ll msmlin=0,ant_coluna=0;
    for(int i=0;i<n;i++){
        ll a,b;cin>>a>>b;
        v.push_back({a,b});
        mapa[a]++;
        existe[{a,b}]=1;
        if(b!=1)tdsy=1;
        if(i==0)prim=a;
        nov[a]++;

        if(i==0)ant_coluna=a;
        else{
            if(ant_coluna!=a)msmlin=1;
        }
    }

    ll qtd_x=mapa.size();
    sort(v.begin(),v.end());

    prim=v[0].first;

    if(tdsy==0){
        cout<<n+1<<'\n';
        cout<<prim<<" "<<2<<'\n';
        for(int i=0;i<n;i++)cout<<v[i].first<<" "<<v[i].second<<'\n';

        return 0;
    }

    if(msmlin==0){
       // cout<<"aqui"<<endl;
        int x=ant_coluna;
        if(x==1e9){
            cout<<n+1<<'\n';
            cout<<x-1<<" "<<1<<'\n';
            for(int i=0;i<n;i++)cout<<v[i].first<<" "<<v[i].second<<'\n';
        }
        else{
            cout<<n+1<<'\n';
            cout<<x+1<<" "<<1<<'\n';
            for(int i=0;i<n;i++)cout<<v[i].first<<" "<<v[i].second<<'\n';
        }

        return 0;
    }

    ll x_ant=0;
    ll tem2=0;
    ll qtd=0;

    if(v[0].first==prim and v[0].second!=1){
        dps.push({prim,1});
        existe[{prim,1}]=1;
        mapa[prim]++;
    }

    ll aux2=0;
    ll ulty=v[n-1].first;
    
    for(int i=0;i<n;i++){
        ll x=v[i].first;
        ll y=v[i].second;

        if(x!=x_ant){
            x_ant=x;
            qtd=0;
        }

        qtd++;

        if(x==ulty){//imprime ao contrario - do maior pro menor
            // se eh o primeiro, ve se eh o 1 + se o anterior tem algum 
            if(mapa[x-1]==0){ // nao tem 
                fim.push_back({x-1,2});
                existe[{x-1,2}]=1;
                mapa[x-1]++;
            }

            if(qtd==1){
                if(y!=1){
                    dps.push({x,1});
                }

                dps.push({x,y});
            }
            else{//cc, so coloca ao contrario no dps 
                dps.push({x,y});
            }
            
            
            continue;
        }

        if(y==1){// coloca no dps
            dps.push({x,y});
        }
        else if(y==2){ // coloca no 1 
            fim.push_back({x,y});
        }
        else{ // coloca no 2 
            if(existe[{x,2}]!=1){
                if(prim!=x){
                    fim.push_back({x,2});
                    existe[{x,2}]=1;
                    mapa[x]++;
                }
            }
            
            fim.push_back({x,y});

            if(nov[x]==qtd){// eh o mais e cima da coluna, e nao existe o 2 do proximo, coloca ele 
            //    cout<<"x:"<<x<<" "<<y<<" aqui\n";
                //ve se o prox existe e coloca la 
                if(existe[{x+1,2}]!=1 and x+1!=ulty){
                    fim.push_back({x+1,2});
                    existe[{x+1,2}]=1;
                    mapa[x+1]++;
                }
                
            }
        }
    
    }

    cout<<fim.size()+dps.size()<<'\n';
    for(int i=0;i<fim.size();i++)cout<<fim[i].first<<" "<<fim[i].second<<'\n';
    while(!dps.empty()){
        auto [a,b]=dps.top();
        dps.pop();
        cout<<a<<" "<<b<<'\n';
    }

}
