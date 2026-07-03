#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll n;cin>>n;
    ll sum=300;
    for(int i=0;i<n;i++){
        ll v;cin>>v;
        sum+=v;
    }

    if(sum<=420){
        cout<<sum-300<<'\n';
    }
    else if(sum>420){
        sum+=180;
        if(sum>1020){
            sum+=180;
            cout<<sum-300<<'\n';
        }
        else{
            cout<<sum-300<<'\n';
        }
    }
}
