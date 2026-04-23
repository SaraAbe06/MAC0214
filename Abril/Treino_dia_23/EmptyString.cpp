//AC
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
const ll maxn=510;

ll fat[maxn];
ll invfat[510];

ll mult(ll a,ll b){
    return (1ll*(a%mod)*(b%mod))%mod;
}

ll soma(ll a,ll b){
    return (a+b)%mod;
}

ll fexp(ll a, ll b){
    if(b==1)return a;

    ll mid=fexp(a,b/2);
    if(b%2==0)return mult(mid,mid);
    else return mult(a,mult(mid,mid));
}

ll inv(ll num){
    return fexp(num,mod-2);
}

ll conta(ll a,ll b){
    return mult(fat[a],mult(invfat[b],invfat[a-b]));
}

ll dp[510][510];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;cin>>s;
    ll n=s.size();

    if(n%2==1){
        cout<<0<<'\n';
        return 0;
    }

    fat[0]=1;
    fat[1]=1;
    for(int i=2;i<=508;i++){
        fat[i]=mult(fat[i-1],i);
    }

    invfat[508-1] = inv(fat[508-1]);
    for(int i=508-2;i>=0;i--){
        invfat[i]=mult(invfat[i+1],i+1);
    }

    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1])dp[i][i+1]=1;
    }
    

    for(int j=1;j<=n;j++){
        if((j+1)%2==1)continue;

        for(int i=0;i<n-j;i++){
            if(i+1<=i+j){
                if(s[i]==s[i+1]){
                    dp[i][i+j]=soma(dp[i][i+j],mult(dp[i+2][i+j],((i+j-(i+2)+1))/2+1));
                }
            }
            for(int k=i+2;k<=i+j;k++){
                if(s[i]==s[k]){
                    if(k==i+j){
                        dp[i][i+j]=soma(dp[i][i+j],dp[i+1][k-1]);
                    }
                    else{
                        ll t1=((k-1-(i+1)+1)/2);
                        ll t2=((i+j-(k+1)+1)/2);
                        ll t=t1+t2+1;
                        ll tot_aux=mult(dp[i+1][k-1],dp[k+1][i+j]);
                        tot_aux=mult(tot_aux,conta(t,t2));
                        dp[i][i+j]=soma(dp[i][i+j],tot_aux);
                    }
                }
               
            }
        }
    }

  //  for(int i=0;i<=n;i++){
    //    for(int j=0;j<=n;j++){
      //      cout<<dp[i][j]<<" ";
        //}

        //cout<<endl;
    //}

   cout<<dp[0][n-1]<<'\n';

}