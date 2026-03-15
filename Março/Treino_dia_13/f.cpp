#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=1e5+10;
ll a[maxn],b[maxn];
ll sa=0,sb=0;

int main(){
    ll n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        sa+=a[i];
        sb+=b[i];
    }

    ll ind=-1;
    for(int i=1;i<=n;i++){
        ll qtd=max(0ll,sb-(sa-a[i]));
        if(qtd<=b[i]){
            ind=i;
            break;
        }
    }

    if(ind==-1){
        cout<<"impossible"<<'\n';
    }
    else cout<<ind<<'\n';
}
