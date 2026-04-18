#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;

ll saldo[18];
ll dp[(1<<16)+1];
vector<ll>deve;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll n,m;cin>>n>>m;
    if(m==0)cout<<0<<'\n';
    else{
        for(int i=0;i<m;i++){
            ll v,p,k;cin>>p>>v>>k;
            saldo[p]+=v*k;
            for(int j=0;j<k;j++){
                ll pes;cin>>pes;
                saldo[pes]-=v;
            }

           // cout<<i<<endl;
        }

       // cerr<<"a"<<endl;
       
        for(int i=1;i<=n;i++){
          //  if(saldo[i]!=0){
                deve.push_back(i);
            //}
        }

       // cout<<"aqui";
        ll tam=deve.size();

        for(ll mask=0;mask<=(1ll<<tam)-1;mask++){
            
            ll soma=0;
            for(int i=0;i<tam;i++){
                if((1ll<<i)&mask){
                    soma+=saldo[deve[i]];
                }
            }

            if(soma!=0){
                dp[mask]=0;
                continue;
            }
           

            for(ll j=mask;j>0;j=(j-1)&mask){
                dp[mask]=max(dp[mask],dp[j]+1);
              //  cerr <<j<<endl;
            }
        }

        cout<<n-dp[(1ll<<tam)-1]<<'\n';

    }


}
