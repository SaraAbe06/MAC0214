#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll ini=0,fim=0;
        ll vi=0,vf=0;
        ll tot=0;

        for(int i=0;i<n;i++){
            ll a;cin>>a;
            if(i==0){
                vi=a;
                vf=a;
                ini=a,fim=a;
            }
            else{
                if(a>=ini+1 and a<=fim+1){
                    fim=a;
                    vf++;
                    //cout<<a<<" aqio"<<endl;
                }
                else{
                    tot++;
                    vi=i;vf=i;
                    ini=a,fim=a;
                }
            }
        }

        cout<<tot+1<<'\n';
    }
}
