#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=1e4+2;
ll posi[maxn];
string vet[maxn];
map<string,ll>freq;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll n,c;cin>>n>>c;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        vet[i]=s;
        for(int j=0;j<c;j++){
            if(s[j]=='*'){posi[i]=j;break;}
        }

        for(int j=0;j<26;j++){
            string nova=s;
            char a=(char)('a'+j);
            nova[posi[i]]=a;

            freq[nova]++;
        }
    }

    string res="";
    ll qtd=0;

    for(auto it=freq.begin();it!=freq.end();it++){
        ll qq=it->second;
        if(qq>qtd){res=it->first;qtd=qq;}
        else if(qq==qtd){
            if(res==""){
                res=it->first;
                qtd=qq;
            }
            else if(res>(it->first)){
                res=it->first;
                qtd=qq;
            }
        }
    }

    cout<<res<<" "<<qtd<<'\n';
}
