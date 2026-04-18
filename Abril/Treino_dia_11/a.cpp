#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll visi[60];
char dir[60];

int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>dir[i];
            visi[i]=0;
        }

        ll ind=1;
        visi[ind]=1;
        for(int i=1;i<=n;i++){
            if(dir[ind]=='L'){
                ind--;
                visi[ind]=1;
            }
            else{
                ind++;
                visi[ind]=1;
            }
        }
        ll tot=0;
        for(int i=1;i<=n;i++){
            tot+=visi[i];
        }

        cout<<tot<<'\n';
    }
}
