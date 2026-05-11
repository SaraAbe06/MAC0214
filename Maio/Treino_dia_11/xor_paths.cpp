//ac
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>v;
map<ll,ll> qtd[22][22];
ll k,n,m;
ll mat[22][22];

void geratds(ll l, ll r){
    ll len=r-l+1;

    for(int i=0;i<(1ll<<len);i++){
        ll sum=mat[1][1];
        ll xs=1,ys=1;
        ll impossiv=0;
        for(int j=0;j<len;j++){
            if(i & (1ll<<j)){// eh 1
                xs++;
            }
            else{// eh 0
                ys++;
            }

            if(xs>n or ys>m)impossiv=1;
            if(impossiv==1)break;
            sum^=mat[xs][ys];
        }

        if(impossiv==0)qtd[xs][ys][sum]++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mat[i][j];
        }
    }

    ll passos=n+m-2;
    if(passos==0){
        if(mat[1][1]==k)cout<<1<<'\n';
        else cout<<0<<'\n';
        return 0;
    }

    ll mid=(n+m-2)/2;
    geratds(0,mid-1);
    
    ll ans=0;
    ll len=(n+m-2)-mid;

    for(int i=0;i<(1ll<<len);i++){
        ll sum=mat[n][m];
        ll xs=n,ys=m;
        ll impossiv=0;

        for(int j=0;j<len;j++){
            if(i & (1ll<<j)){// eh 1
                xs--;
            }
            else{// eh 0
                ys--;
            }

            if(xs<1 or ys<1)impossiv=1;
            if(impossiv==1)break;
            sum^=mat[xs][ys];
        }

        if(impossiv==0){
            ans+=(qtd[xs][ys][k^sum^mat[xs][ys]]);
        }
    }

    cout<<ans<<'\n';
    

}