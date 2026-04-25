#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll t;cin>>t;
    while(t--){
        ll val=1;

        ll a,b;cin>>a>>b;
        ll qtd=0;

        for(int i=0;i<61;i++){
            if(val>=a and val<=b)qtd++;
          
            val=2*val;
        }

        cout<<qtd<<'\n';

    
    }
}
