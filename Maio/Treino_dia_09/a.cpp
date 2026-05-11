#include<bits/stdc++.h>
using namespace std; 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;cin>>t;
    while(t--){
        int n,m,d;
        cin>>n>>m>>d;

        int maximo=(int)(d/m)+1;
        int qtd=(n/maximo);
        if(n%maximo!=0)qtd++;

        cout<<qtd<<'\n';
    }
}
