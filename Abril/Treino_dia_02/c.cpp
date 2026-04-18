//ac
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=1e5+10;

map<vector<ll>,ll>mapa;
vector<ll> g[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        ll tam=s.size()/2;
        tam--;

        vector<ll>v;
        for(int j=0;j<=tam;j++){
            ll num=((s[j]-'a'))-((s[m-j-1]-'a'));
            num=(num+26)%26;
            v.push_back(num);
        }

        mapa[v]++;
        g[i]=v;

    }

    ll tot=0;

    for(int i=0;i<n;i++){
        vector<ll>vet=g[i];
        vector<ll>aux;
        for(int j=0;j<vet.size();j++){
            ll num=(26-vet[j])%26;
            aux.push_back(num);
        }

        tot+=mapa[aux];
    }

    cout<<tot<<'\n';
}