#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 

map<char,ll>mapa;
map<char,ll>mapa2;
ll tot;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n,l,r;cin>>n>>l>>r;
    string s;cin>>s;
    l--;

    for(int i=0;i<=r;i++){
        mapa[s[i]]++;
    }

    for(auto it=mapa.begin();it!=mapa.end();it++){
        ll val=it->second;
        if(val!=0){
            tot+=(((val)*(val-1))/2);
        }
    }

    int ind=0;
    for(int i=r+1;i<s.size();i++){
        mapa[s[ind]]--;
        ind++;
        tot+=mapa[s[i]];
        mapa[s[i]]++;
    }

    for(int i=0;i<=l;i++){
        mapa2[s[i]]++;
    }

    ll tot2=0;
    for(auto it=mapa2.begin();it!=mapa2.end();it++){
        ll val=it->second;
        if(val!=0){
            tot2+=(((val)*(val-1))/2);
        }
    }

    ind=0;
    for(int i=l+1;i<s.size();i++){
        mapa2[s[ind]]--;
        ind++;
        tot2+=mapa2[s[i]];
        mapa2[s[i]]++;
    }

    cout<<tot-tot2<<'\n';


}