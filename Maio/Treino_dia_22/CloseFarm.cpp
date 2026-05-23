#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=1e5+10;
ll pai[2*maxn];
ll sizes[2*maxn];
ll tam;

vector<ll>adj[2*maxn];


ll ache(int x){
    if(pai[x]==x)return x;
    return pai[x]=ache(pai[x]);
}

ll v1=-1,v2=-1;

ll join(int x,int y){
    int x_pai=ache(x);
    int y_pai=ache(y);
    if(x_pai==y_pai)return 0;

    v1=sizes[x_pai],v2=sizes[y_pai];
    if(sizes[x_pai]<sizes[y_pai])swap(x_pai,y_pai);
    sizes[x_pai]+=sizes[y_pai];
    pai[y_pai]=x_pai;
    return sizes[x_pai];
}

bool tao_junto(int x,int y){
    return ache(x)==ache(y);
}

vector<ll>ordem;
vector<string>res;

ll tot=0;
ll aqui[2*maxn];

int main(){
    freopen("closing.in","r",stdin);
    freopen("closing.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        pai[i]=i;
        sizes[i]=1;
    }

    for(int i=0;i<m;i++){
        ll a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=0;i<n;i++){
        ll a;cin>>a;
        ordem.push_back(a);
    }

   

    reverse(ordem.begin(),ordem.end());

    for(auto p:ordem){
        tot++;
        aqui[p]++;

        if(tot==1){
            res.push_back("YES");
            continue;
        }

        for(auto u:adj[p]){
            if(aqui[u]){
                ll k=join(u,p);

                if(k!=0)tot--;

            }
        }

        if(tot==1)res.push_back("YES");
        else res.push_back("NO");
    }

    reverse(res.begin(),res.end());
    for(auto p:res)cout<<p<<'\n';


}