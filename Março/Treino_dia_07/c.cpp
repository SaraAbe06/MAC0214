#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>par;
const ll maxn=1e5+3;
vector<ll>v;
vector<par>ord;
ll aux[3*maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

   ll n,q;cin>>n>>q;
   for(int i=0;i<n;i++){
    ll a;cin>>a;
    v.push_back(a);
    ord.push_back({a,i});
   }

   sort(ord.begin(),ord.end());
   for(int i=0;i<n;i++){
    aux[ord[i].second]=i+1;
   }

  // cout<<"valores:"<<endl;
   //for(int i=0;i<n;i++){
   // cout<<i<<" "<<v[i]<<" "<<ord[i].first<<" "<<ord[i].second<<" "<<aux[i]<<endl;
   //}

   for(int i=0;i<q;i++){
    ll k;cin>>k;
    vector<ll>val;
    for(int j=0;j<k;j++){
        ll num;cin>>num;
        num--;
        val.push_back(aux[num]);
    }

    sort(val.begin(),val.end());

    int minimo=1;
    for(int j=0;j<k;j++){
        if(val[j]==minimo)minimo++;
    }

    cout<<ord[minimo-1].first<<'\n';
   }


}
