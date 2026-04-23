//AC
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[510][510];
ll c[510];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;cin>>n;
    for(int i=0;i<n;i++)cin>>c[i];
    for(int i=0;i<n;i++)dp[i][i]=1;

    for(int j=1;j<=n;j++){
        for(int i=0;i<n-j;i++){
            dp[i][i+j]=dp[i+1][i+j]+1;
            if(i+1<=i+j){
                if(c[i+1]==c[i]){
                    dp[i][i+j]=min(dp[i][i+j],1+dp[i+2][i+j]);
                }
            }
            for(int k=i+2;k<=i+j;k++){
                if(c[i]==c[k]){
                    dp[i][i+j]=min(dp[i][i+j],dp[i+1][k-1]+dp[k+1][i+j]);
                }
            }
        }
    }

    cout<<dp[0][n-1]<<'\n';

}
