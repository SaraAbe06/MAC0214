#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        string s;cin>>s;
        ll num5=0,num6=0;
        string parcial="";
        for(int i=0;i<n;i++){
            if(s[i]=='2' and i+3<n){
               if(s[i]=='2' and s[i+1]=='0' and s[i+2]=='2' and s[i+3]=='5')num5++;
               if(s[i]=='2' and s[i+1]=='0' and s[i+2]=='2' and s[i+3]=='6')num6++;
            }
        }
        //cout<<"t: "<<t<<" "<<num5<<" "<<num6<<'\n';

        if(num6>=1 or num5==0)cout<<"0"<<'\n';
        else cout<<"1"<<'\n';
    }
}
