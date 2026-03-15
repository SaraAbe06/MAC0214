#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p[1010];
ll tot=0;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>p[i];

    for(int i=0;i<n;i++){
        ll a,b;cin>>a>>b;
       // cout<<i<<" "<<p[a]<<" "<<b<<endl;
        if(p[a]>=b){
            tot+=b;
            p[a]-=b;
        }
        else{
            tot+=p[a];
            p[a]=0;
        }


    }

    cout<<tot<<'\n';
}
