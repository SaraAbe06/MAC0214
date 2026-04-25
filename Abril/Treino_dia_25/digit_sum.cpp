//AC - digit dp, guardo qtd e soma 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>par;

par dp[20][2][2]; // dp[pos][under][started] = (qtd, soma)
string num;

void reset(){
    for(int i=0;i<19;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                dp[i][j][k]={-1,-1};
            }
        }
    }
}

par solve_dp(ll pos,bool under, bool started){
    if(pos==num.size()){
        if(!started)return {0,0};
        return {1,0};
    }

    if(dp[pos][under][started].first!=-1)return dp[pos][under][started];

    par ans={0,0};
    for(int i=0;i<=9;i++){
        int digit_diff=num[pos]-'0';
        if(!under and i>digit_diff)break;

        bool is_under=under;
        if(i<digit_diff)is_under=true;

        bool is_started=started || i!=0;

        auto [q,s]=solve_dp(pos+1,is_under,is_started);
        ans.first+=q;
        ans.second+=(s+q*i);
    }

    return dp[pos][under][started]=ans;
}

ll conta(ll a){
    if(a==-1){
        return 0;
    }
    num=to_string(a);
    reset();
    auto [q,s]=solve_dp(0,false,false);
    return s;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll t;cin>>t;
    while(t--){
        ll a,b;cin>>a>>b;
        cout<<conta(b)-conta(a-1)<<'\n';
    }

}