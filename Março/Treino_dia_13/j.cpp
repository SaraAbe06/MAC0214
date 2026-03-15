#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 

const ll maxn=1e5+10;
ll viagem[maxn];

struct evento{
    ll pessoa;
    ll tipo;
    ll tt;
    ll ind_v;
};

bool compara( const evento& e1, const evento& e2){
    return e1.tt<e2.tt;
}

set<ll>pp;
vector<evento>v;
void addevento(ll a,ll b, ll c, ll d){
    evento e;
    e.pessoa=a;
    e.tipo=b;
    e.tt=c;
    e.ind_v=d;

    v.push_back(e);
    return;
}

ll qtd=0,maior=0;

int main(){
    ll n,k,q;cin>>n>>k>>q;
    for(int i=1;i<=q;i++){
        ll p,l,r;cin>>p>>l>>r;

        addevento(p,1,l,i);
        addevento(p,2,r,i);
    }

    sort(v.begin(),v.end(),compara);

    for(int i=0;i<v.size();i++){
        ll p=v[i].pessoa;
        ll tipo=v[i].tipo;
        ll ind=v[i].ind_v;

        if(tipo==2){
            if(pp.size()==n){
                viagem[ind]=1;
            }
            pp.erase(p);
        }
        else{
            pp.insert(p);
        }
    }

    for(int i=0;i<v.size();i++){
        ll p=v[i].pessoa;
        ll tipo=v[i].tipo;
        ll ind=v[i].ind_v;

        if(viagem[ind]==1){
            if(tipo==1)k--;
            else k++;
        }

        if(k<0)qtd=1;
    }

    if(qtd==1)cout<<"impossible"<<'\n';
    else{
        for(int i=1;i<=q;i++)cout<<viagem[i];
    }
}
