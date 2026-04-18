#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mdc(ll a,ll b){
    if(b==0)return a;
    return mdc(b,a%b);
}

ll mmc(ll a,ll b){
    return (a*b)/mdc(a,b);
}

ll qtd(ll val, ll mult){
    return (ll)(val/mult);
}

int main(){
    ll t;cin>>t;
    while(t--){
        ll a,b,c,m;cin>>a>>b>>c>>m;
        ll ta=0,tb=0,tc=0;

        ll m1=mmc(a,b),m2=mmc(a,c),m3=mmc(b,c);

        ll A=qtd(m,a);
        ll B=qtd(m,b);
        ll C=qtd(m,c);
        ll a_b=qtd(m,m1);
        ll a_c=qtd(m,m2);
        ll b_c=qtd(m,m3);
        ll a_b_c=qtd(m,mmc(a,m3));

        ta=6*(A-(a_b+a_c-a_b_c))+3*(a_b+a_c-2*a_b_c)+2*a_b_c;
        tb=6*(B-(a_b+b_c-a_b_c))+3*(a_b+b_c-2*a_b_c)+2*a_b_c;
        tc=6*(C-(a_c+b_c-a_b_c))+3*(a_c+b_c-2*a_b_c)+2*a_b_c;

        cout<<ta<<" "<<tb<<" "<<tc<<'\n';
    }
}