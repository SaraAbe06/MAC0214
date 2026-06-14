#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll t;cin>>t;
    while(t--){
        ll a,b;cin>>a>>b;
        ll k1=0,k2=0,l1=0,l2=0;
        ll num=4;
        for(int i=0;i<16;i++){
            if((num-1)/3<=a)k1=i+1;
            if((num*2-2)/3<=b)k2=i+1;
            if((num-1)/3<=b)l1=i+1;
            if((num*2-2)/3<=a)l2=i+1;

            num=num*4;
        }

        //cout<<"ks: "<<k1<<" "<<k2<<" "<<l1<<" "<<l2<<'\n';
        ll maior=0;
        if(k1>k2){
            maior=2*k2+1;
        }
        else maior=2*k1;

        if(l1>l2)maior=max(maior,2*l2+1);
        else maior=max(maior,2*l1);

        cout<<maior<<'\n';
    }
}