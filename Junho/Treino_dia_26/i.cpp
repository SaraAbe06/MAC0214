#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

set<string>finais;

ll num_str(string s){
    ll aux=0;
    for(int i=0;i<s.size();i++){
        ll dig=s[i]-'0';
        aux*=10;
        aux+=dig;
    }

    return aux;
}

ll confere(string s){
    ll a=1;
    if(s[0]!='1' or s[2]!='9')a=0;
    if(s[1]=='0')a=0;
    return a;
}

string d;
ll resto;

void rec(ll falta, ll ind, string atual,ll tam,ll usou){
    if(tam==11){
        if(usou==d.size() and falta==0){
            if(confere(atual)==1){finais.insert(atual);return;}
            else return;
        }
        else return;
    }

    string aux="";

    rec(falta-1,ind,atual+"1",tam+1,usou);
    rec(falta-1,ind,atual+"9",tam+1,usou);

    if(usou!=d.size()){
        aux+=d[ind];
        rec(falta,ind+1,atual+aux,tam+1,usou+1);
    }
    
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>d;

    if(d.size()>11)cout<<0<<'\n';
    else if(d.size()==11){
     
        if(confere(d)==1){
            cout<<1<<'\n';
            cout<<d;
        }
        else{
            cout<<0<<'\n';
        }
    }
    else{
        rec(11-d.size(),0,"",0,0);
        cout<<finais.size()<<endl;
        for(auto p:finais){
            cout<<p<<endl;
        }
    }
}
