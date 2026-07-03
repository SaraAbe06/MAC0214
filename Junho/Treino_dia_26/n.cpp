#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>v;
ll S,M;
vector<ll>res;
ll sum=0;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;cin>>n;
    for(int i=0;i<n+2;i++){
        ll a;cin>>a;
        v.push_back(a);
        sum+=a;
    }

    sort(v.begin(),v.end());

    S=v[n+1];
    M=sum-n*S;

    ll achou=0;

    for(int i=0;i<n+1;i++){
        if(achou==0){
            if(M==v[i])achou=1;
            else res.push_back(S-v[i]);
        }
        else{
            res.push_back(S-v[i]);
        }
    }

    sort(res.begin(),res.end());


    cout<<S<<" "<<M<<'\n';
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }

    
}
