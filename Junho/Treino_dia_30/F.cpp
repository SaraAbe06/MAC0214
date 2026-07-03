#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>par;

const ll maxn=300100;

ll pai[maxn];
ll sizes[maxn];
ll maior[maxn];

ll qtds[maxn];

ll ache(int x){
    if(pai[x]==x)return x;
    return pai[x]=ache(pai[x]);
}

ll v1=-1,v2=-1;

ll join(int x,int y){
    int x_pai=ache(x);
    int y_pai=ache(y);
    
    return pai[x_pai]=y_pai;
}

stack<par>pilha;

ll atual[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){cin>>qtds[i];pai[i]=i;}
    pai[n+1]=n+1;

    for(int i=n;i>=1;i--){
        while(!pilha.empty()){
            par aux=pilha.top();
            if(aux.second<=qtds[i])pilha.pop();
            else break;
        }

        if(pilha.empty()){
            maior[i]=n+1;
            pilha.push({i,qtds[i]});
        }
        else{
            maior[i]=pilha.top().first;
            pilha.push({i,qtds[i]});
        }
    }

    while(q--){
        char c;cin>>c;
        if(c=='+'){
            ll l,x;cin>>l>>x;
            l=ache(l);
            if(l==n+1)continue;
            
            if(atual[l]+x<=qtds[l]){
                atual[l]+=x;
            }
            else{

                ll novo=ache(l);
                while(x!=0){
                    x-=(qtds[novo]-atual[novo]);
                    atual[novo]=qtds[novo];
                    join(novo,maior[novo]);
                    novo=ache(novo);
                    if(novo==n+1)break;
                    else{
                        if(atual[novo]+x<=qtds[novo]){
                            atual[novo]+=x;
                            break;
                        }

                    }
                }
              
            }
        }
        else{
            ll l;cin>>l;
            cout<<atual[l]<<'\n';
        }
    }
    


}
