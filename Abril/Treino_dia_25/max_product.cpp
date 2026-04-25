//AC - ideia: vc testa tds q na posicao i troca por um menor e os da direita vira 9
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll nove[20];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll a,b;cin>>a>>b;
    string s=to_string(b);
    ll maximo=1;

    for(int i=0;i<s.size();i++){
        ll num=s[i]-'0';
        maximo=maximo*num;
    }

    nove[0]=1;
    nove[1]=9;
    for(int i=2;i<=19;i++){
        nove[i]=nove[i-1]*9;
    }

    ll anteriores=1;
    ll numero=b;

    for(int i=0;i<s.size();i++){
        ll num=s[i]-'0';
        if(num==0){
            anteriores=anteriores*num;
            continue;
        }

    //cout<<i<<" "<<num<<endl;
        num--;
        s[i]=(char)(num+'0');
        ll aux=0;
        if(i==0 and num==0) aux=anteriores*nove[s.size()-1-i];
        else aux=anteriores*(num)*nove[s.size()-1-i];

        string novo="";
        for(int j=0;j<s.size();j++){
            if(j<=i)novo+=s[j];
            else novo+=(char)(9+'0');
        }


       //cout<<aux<<" "<<stoll(novo)<<" "<<endl;
        
        if(stoll(novo)>=a){
            if(aux>maximo){
                maximo=aux;
                numero=stoll(novo);
            }
        }
        num++;
        s[i]=(char)(num+'0');
       
        anteriores=anteriores*num;
    }

    cout<<numero<<'\n';

}
