#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 

int main(){
  ll h,w,q;cin>>h>>w>>q;

  while(q--){
    ll a,b;cin>>a>>b;

    if(a==1){
        cout<<b*w<<'\n';
        h-=b;
    }
    else{
        cout<<b*h<<'\n';
        w-=b;
    }
  }
}