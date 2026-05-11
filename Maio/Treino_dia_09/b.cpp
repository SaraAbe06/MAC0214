#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;

int vet[20];
int jafoi[20];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        ll sum=0;
        for(int i=0;i<s.size();i++){
            int val=s[i]-'0';
            vet[i]=val;
            sum+=val;
            jafoi[i]=0;
        }

        //cout<<sum<<endl;

        if(sum<10){
            cout<<0<<'\n';
        }
        else{

            int tot=0;

            while(sum>=10){
                int maior=0,ind=-1;
                for(int i=0;i<s.size();i++){
                    if(i==0){
                        maior=vet[i]-1;
                        ind=i;
                    }
                    else if(vet[i]>maior and jafoi[i]==0){
                        maior=vet[i];
                        ind=i;
                    }
                }

                if(ind==0){
                    sum=sum-maior;
                    vet[ind]=1;
                }
                else{
                    sum-=maior;
                    vet[ind]=0;
                }
                jafoi[ind]=1;
                maior=0;
                tot++;
            }

            cout<<tot<<'\n';
        }
    }
}
