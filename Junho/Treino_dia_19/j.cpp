#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>par;
typedef pair<par,ll>par2; 

vector<par2>v;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;cin>>n;
    for(int i=0;i<n;i++){
        ll x,y,h;cin>>x>>y>>h;
        v.push_back({{x,y},h});
    }

    for(int i=0;i<n;i++){
        long double x1=(long double)v[i].first.first;
        long double y1=(long double)v[i].first.second;
        ll raio=v[i].second;

       // cout<<i<<" "<<raio<<endl;

        for(int j=0;j<n;j++){
            if(j==i)continue;

            long double x=(long double)v[j].first.first;
            long double y=(long double)v[j].first.second;
            ll h=v[j].second;

            if(h>v[i].second){
                ll dist=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
             //   cout<<j<<" "<<i<<" "<<dist<<" aa"<<endl;
                if(dist<raio)raio=dist;
            }
        }

        cout<<raio<<endl;
    }

}
