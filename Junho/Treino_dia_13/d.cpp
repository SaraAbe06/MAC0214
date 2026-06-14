#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=998244353;
ll a[60];
ll b[60];

ll mult(ll a,ll b){
    return 1ll*(a*b)%mod;
}
ll soma(ll a,ll b){
    return (a+b)%mod;
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll sum=0;
        for(int i=0;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
            b[i]=a[i];
        }

        ll k=sum/n;
        ll flag=0;
        ll z=0;
        for(int i=1;i<=n;i++){
            if(b[i]>=k)b[i]-=k;
            else{
                b[0]=b[0]-(k-b[i]);
                b[i]=0;
            }

            if(b[i]>1)flag=1;
            if(b[i]==0)z++;
        }

       // cout<<b[0]<<" "<<b[1]<<endl;

        if(b[0]<0 or flag==1)cout<<"0"<<'\n';
        else{
            if(z-b[0]<0)cout<<"0"<<'\n';
            else{
               // cout<<"AQUI"<<endl;
                ll x=z-b[0];
                ll p1=z;
                ll p2=n-x;

                if(p1==0)p1=1;
                if(p2==0)p2=1;

                for(ll i=p2-1;i>=0;i--){
                    if(i!=0)p2=mult(p2,i);
                }

                for(ll i=z-1;i>z-x;i--){
                    p1=mult(p1,i);
                }

                cout<<mult(p1,p2)<<'\n';
            }
        }


    }
}