//AC
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[252][252];
ll s[252];
ll maior=0;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    freopen("248.in","r", stdin);
    freopen("248.out","w", stdout);
    ll n;cin>>n;
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<n;i++)dp[i][i]=s[i];

    for(int j=0;j<=n;j++){
        for(int i=0;i<n-j;i++){
            maior=max(maior,dp[i][i]);
            for(int k=i;k<i+j;k++){
                if(dp[i][k]==dp[k+1][i+j] and dp[i][k]!=0){
                    dp[i][i+j]=max(dp[i][i+j],dp[i][k]+1);
                    maior=max(maior,dp[i][i+j]);
                }
            }
        }
    }

    cout<<maior<<'\n';
}