#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=1e5+10;
ll pai[maxn];
ll sizes[maxn];
ll tam;

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

multiset<ll>ms;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n,m;cin>>n>>m;

    for(int i=1;i<=n;i++){pai[i]=i;ms.insert(1);sizes[i]=1;}

    for(int i=0;i<m;i++){
        ll a,b;cin>>a>>b;
        ll val=join(a,b);

        //cout<<val<<endl;

        if(val==0){
            cout<<ms.size()<<" "<<*ms.rbegin()<<'\n';
        }
        else{
            auto it=ms.find(v1);
            ms.erase(it);
            it=ms.find(v2);
            ms.erase(it);

            ms.insert(val);

            cout<<ms.size()<<" "<<*ms.rbegin()<<'\n';
        }
    }


}
