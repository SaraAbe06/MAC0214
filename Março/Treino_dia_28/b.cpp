#include<bits/stdc++.h>
using namespace std;

int ma[110],mb[110];

int main(){
   int n,m;cin>>n>>m;
   for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;
    ma[a]++;
    mb[b]++;
   }

   for(int i=1;i<=m;i++) cout<<mb[i]-ma[i]<<'\n';
   
}