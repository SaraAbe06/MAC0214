#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        string s;cin>>s;
        ll num=0;
        ll tot=0;

        if(n==1){
            cout<<1<<'\n';
        }
        else{
            for(int i=0;i<n;i++){
                if(s[i]==1){
                    tot++;
                    if(num>0){
                        tot+=num/3;
                        if(num%3!=0)tot++; 
                        num=0;
                    }
                }
                else{
                    if(i==0){
                       // cout<<"aqui1"<<endl;
                        if(s[i+1]=='0')num++;
                        else{
                            tot+=num/3;
                            if(num%3!=0)tot++; 
                            num=0;
                        }
                    }
                    else if(i==n-1){
                       // cout<<"aqui2"<<endl;
                        if(s[i-1]=='0')num++;
                        else{
                            tot+=num/3;
                            if(num%3!=0)tot++; 
                            num=0;
                        }
                    }
                    else{
                       // cout<<"aqui3"<<endl;
                        if(s[i-1]=='0' and s[i+1]=='0')num++;
                        else{
                            tot+=num/3;
                            if(num%3!=0)tot++; 
                            num=0;
                        }
                    }
                }

               // cout<<num<<" aa"<<endl;
            }
            if(num>0){
                //cout<<"aqui:"<<" "<<num<<endl;
                tot+=num/3;
                if(num%3!=0)tot++; 
            }

            cout<<tot<<'\n';
        }

       
      
    }
}
