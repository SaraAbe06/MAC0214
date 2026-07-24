#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c[110][110];

int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);

   ll n;cin>>n;
   for(int i=1;i<=n-1;i++){
    for(int j=i+1;j<=n;j++){
        cin>>c[i][j];
    }
   }

   ll flag=0;

   for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            for(int k=j+1;k<=n;k++){
                if(c[i][j]+c[j][k]<c[i][k]){
                    flag=1;
                    break;
                }
            }
        }
   }

   if(flag==1)cout<<"Yes";
   else cout<<"No";
   
}
