#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maximo=0;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll p1,p2,a;cin>>p1>>p2>>a;

    for(int i=0;i<=a;i++){
        maximo=max(maximo,(ll)p1*(i)*p2*(a-i));
    }

    cout<<maximo<<'\n';
}