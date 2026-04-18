#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        string s;cin>>s;
        if(n%2==1){
            if(s[0]=='b')cout<<"NO"<<'\n';
            else if(n==1)cout<<"YES"<<'\n';
            else{
                ll qa=-1,qb=-1,flag=0;
                for(int i=1;i<s.size();i++){
                    if(i%2==1){
                       if(s[i]==s[i+1] and s[i]!='?' and s[i+1]!='?'){
                        flag=1;
                        break;
                       } 
                    }
                }

                if(flag==1)cout<<"NO"<<'\n';
                else cout<<"YES"<<'\n';
            }
        }
        else{
            ll qa=-1,qb=-1,flag=0;
            for(int i=0;i<s.size();i++){
                if(i%2==0){
                    if(s[i]==s[i+1] and s[i]!='?' and s[i+1]!='?'){
                        flag=1;
                        break;
                    } 
                }
            }
            
            if(flag==1)cout<<"NO"<<'\n';
            else cout<<"YES"<<'\n';
        }
        
    }
}