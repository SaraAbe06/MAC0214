//ac
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>v;
ll m;

vector<ll> geratds(ll l, ll r){
    ll len=r-l+1;
    vector<ll>res;

    for(int i=0;i<(1ll<<len);i++){
        ll sum=0;
        for(int j=0;j<len;j++){
            if(i & (1ll<<j))sum+=v[l+j];
        }

        res.push_back(sum%m);
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n;cin>>n>>m;
    for(int i=0;i<n;i++){
        ll a;cin>>a;
        v.push_back(a);
    }

    if(n==1){
        ll maior=0;
        maior=max(maior,v[0]%m);
        cout<<maior<<'\n';
        return 0;
    }

    vector<ll>left=geratds(0,n/2-1);
  
    sort(left.begin(),left.end());
    ll tam=left.size()-1;
    
    ll ans=0;
    ll len=n-1-(n/2)+1;
    ll l=n/2;

    for(int i=0;i<(1ll<<len);i++){
        ll sum=0;
        for(int j=0;j<len;j++){
            if(i & (1ll<<j))sum+=v[l+j];
        }

        sum%=m;

        ll aux=(sum%m+left[tam]%m)%m;
        auto it=lower_bound(left.begin(),left.end(),m-sum);

        ll ind=it-left.begin();
        if(ind==0){
            aux=max(aux,(sum+left[ind])%m);
        }
        else{
            if(left[ind]<m-sum) aux=max(aux,(sum+left[ind])%m);
            else aux=max(aux,(sum+left[ind-1])%m);
        }

        ans=max(ans,aux);

    }

    cout<<ans<<'\n';
    

}