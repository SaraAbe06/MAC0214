#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=200005;
char mat[3][maxn];
ll dp[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
            }
        }

        if(mat[0][0]!=mat[1][0]){
            dp[0]=1;
        }
        else{
            dp[0]=0;
        }

        for(int i=1;i<n;i++){
            if(mat[0][i]!=mat[1][i])dp[i]=1+dp[i-1];
            else dp[i]=dp[i-1];

            ll aux=0;
            if(mat[0][i]!=mat[0][i-1])aux++;
            if(mat[1][i]!=mat[1][i-1])aux++;

            if(i==1)dp[i]=min(dp[i],aux);
            else dp[i]=min(dp[i],aux+dp[i-2]);
        }

        cout<<dp[n-1]<<'\n';
    }
}