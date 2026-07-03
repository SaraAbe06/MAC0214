#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll ini=1,fim=n;

        vector<int>v;
        ll mid=(n)/2;

        while(true){
           if(n%2==1){
            if(fim>=mid+1)v.push_back(fim);
            if(ini<=mid)v.push_back(ini);
            ini++;
            fim--;
            if(ini>mid and fim<mid+1)break;     
           }
           else{
            if(fim>=mid+1)v.push_back(fim);
            if(ini<=mid)v.push_back(ini);
            ini++;
            fim--;
            if(ini>mid and fim<mid+1)break;     
           }
        }

        for(int i=n-1;i>=0;i--)cout<<v[i]<<" ";
        cout<<'\n';
    }
}
