#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s,t;
    cin>>s>>t;
    ll p,q;cin>>p>>q;
    if(p==0 or q==0)cout<<"=";
    else if(s+t<t+s)cout<<"<";
    else if(s+t>t+s)cout<<">";
    else cout<<"=";
}
