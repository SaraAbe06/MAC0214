//Ainda da TLE para alguns :(
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>par;

const ll maxn=1e5+10;
ll pai[2*maxn];
ll sizes[2*maxn];
ll tam;

vector<par>v;
ll res[2*maxn];
ll tot=0;

vector<par>arestas;
vector<par>indices;

ll ache(int x){
    if(pai[x]==x)return x;
    return pai[x]=ache(pai[x]);
}

ll join(int x,int y){
    int x_pai=ache(x);
    int y_pai=ache(y);
    if(x_pai==y_pai)return 0;

    if(sizes[x_pai]<sizes[y_pai])swap(x_pai,y_pai);
    sizes[x_pai]+=sizes[y_pai];
    pai[y_pai]=x_pai;
    return sizes[x_pai];
}

bool tao_junto(int x,int y){
    return ache(x)==ache(y);
}


stack<ll> testar1[2*maxn];
stack<ll> testar2[2*maxn];
ll tempo=0;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n,m,q;cin>>n>>m>>q;

    for(int i=0;i<m;i++){
        ll a,b;cin>>a>>b;
        arestas.push_back({a,b});
    }

    for(int i=0;i<q;i++){
        ll a,b;cin>>a>>b;
        v.push_back({a,b});

        if(a==b){
            res[i]=0;
            tot++;
            continue;
        }
        indices.push_back({1,m});
        ll mid=(1+m)/2;
        testar1[mid].push(i);

    }

   // cerr<<"aaaaaaaa"<<'\n';

    for(int i=1;i<=n;i++){pai[i]=i;sizes[i]=1;}
    for(auto [a,b]:arestas){
        join(a,b);
    }

    for(int i=0;i<q;i++){
        if(!tao_junto(v[i].first,v[i].second)){
            res[i]=-1;
            tot++;
        }
    }


    while(tot!=q){
       // cerr<<"oi: "<<tot<<endl;
        for(int i=1;i<=n;i++){pai[i]=i;sizes[i]=1;}

        ll ind=0,testou=0;
        for(auto [a,b]:arestas){
            ind++;
            join(a,b);


            if(tempo==0){
                while(!testar1[ind].empty()){
                    ll atual=testar1[ind].top();
                    testar1[ind].pop();
                    if(res[atual]!=0)continue;

                 //   cerr<<"t1:"<<ind<<" "<<atual<<endl;
                    testou++;

                    if(tao_junto(v[atual].first,v[atual].second)){
                        indices[atual].second=ind;
                    }
                    else{
                        indices[atual].first=ind+1;
                    }

                    if(indices[atual].first>m){
                        res[atual]=-1;
                        tot++;
                        continue;
                    }

                    if(indices[atual].first==indices[atual].second){
                        res[atual]=indices[atual].first;
                        tot++;
                    }
                    else{
                        ll aux=(indices[atual].first+indices[atual].second)/2;
                        testar2[aux].push(atual);
                    }
                }
            }
            else{
                while(!testar2[ind].empty()){
                    ll atual=testar2[ind].top();
                     testar2[ind].pop();
                    if(res[atual]!=0)continue;
                   
                    testou++;

                   // cerr<<"t2:"<<ind<<" "<<atual<<endl;

                    if(tao_junto(v[atual].first,v[atual].second)){
                        indices[atual].second=ind;
                    }
                    else{
                        indices[atual].first=ind+1;
                    }

                    if(indices[atual].first>m){
                        res[atual]=-1;
                        tot++;
                        continue;
                    }

                    if(indices[atual].first==indices[atual].second){
                        res[atual]=indices[atual].first;
                        tot++;
                    }
                    else{
                        ll aux=(indices[atual].first+indices[atual].second)/2;
                        testar1[aux].push(atual);
                    }
                }
            }
        }

        tempo=(tempo+1)%2;
    }
   

    for(int i=0;i<q;i++)cout<<res[i]<<'\n';
}