#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=1e5+1;
const ll maxn2=1e6;
ll vet[5*maxn];
ll posi[maxn2+2];
ll bol[maxn2+2];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;cin>>n;
    ll tot=0;
    for(int i=0;i<n;i++){
        cin>>vet[i];
        //cout<<posi[vet[i]-1]<<'\n';

        if(posi[vet[i]+1]!=0 and bol[vet[i]+1]>0){
            bol[vet[i]+1]--;
        }
        else{
            tot++;
        }
        posi[vet[i]]=i+1;
        bol[vet[i]]++;
    }

    cout<<tot<<'\n';

}
