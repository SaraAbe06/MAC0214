#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll t;cin>>t;
    while(t--){
        string s;cin>>s;
        ll i1=0,i2=0;
        ll flag=0;

        for(int i=0;i<s.size();i++){//abab
            if(i%2==0){
                if(s[i]=='a'){
                    i1+=flag;
                    flag=0;
                }
                else{
                    flag=1;
                }
            }
            else{
                if(s[i]=='b'){
                    i1+=flag;
                    flag=0;
                }
                else flag=1;
            }
        }
        if(flag==1)i1++;

        flag=0;

        for(int i=0;i<s.size();i++){//baba
            if(i%2==0){
                if(s[i]=='b'){
                    i2+=flag;
                    flag=0;
                }
                else{
                    flag=1;
                }
            }
            else{
                if(s[i]=='a'){
                    i2+=flag;
                    flag=0;
                }
                else flag=1;
            }
        }
        if(flag==1)i2++;

        if(i1<=1 or i2<=1)cout<<"YES\n";
        else cout<<"NO\n";
        
    }
}