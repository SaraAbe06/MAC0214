//ac
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,mid;
ll mat[27][4];
map<tuple<ll,ll,ll>,string>mapa;
map<tuple<ll,ll,ll>,ll>mapa2;

ll valor=0;
string res="";
ll vazio=0;

void rec(ll elem, ll l,ll m,ll w,string s){
    if(elem==0){
     //   cout<<"guarda: "<<l<<" "<<m<<" "<<w<<" "<<s<<'\n';
        ll tot=0;
        for(int i=0;i<s.size()/2;i++){
            if(s[2*i]=='L')tot+=mat[i+1][1];
            else if(s[2*i+1]=='L')tot+=mat[i+1][1];
        }

        if(mapa.count({l-m,m-w,w-l})){
            if(tot>mapa2[{l-m,m-w,w-l}]){
                mapa2[{l-m,m-w,w-l}]=tot;
                mapa[{l-m,m-w,w-l}]=s;
            }
        }
        else{
            mapa[{l-m,m-w,w-l}]=s;
        }
        return;
    }
    
    rec(elem-1,l+mat[mid-elem+1][1],m+mat[mid-elem+1][2],w,s+"LM");
    rec(elem-1,l+mat[mid-elem+1][1],m,w+mat[mid-elem+1][3],s+"LW");
    rec(elem-1,l,m+mat[mid-elem+1][2],w+mat[mid-elem+1][3],s+"MW");

}

int achou=0;
ll tam=0;

void procura(ll elem,ll l,ll m,ll w,string s){
    if(elem==0){

        if(mapa.count({m-l,w-m,l-w})==1){ //
            achou=1;
          //  cout<<"valores: "<<l<<" "<<m<<" "<<w<<" "<<s<<endl;
            string aux=mapa[{m-l,w-m,l-w}]+s;
            ll val_aux=0;

            for(int i=0;i<n;i++){
                if(aux[2*i]=='L')val_aux+=mat[i+1][1];
                else if(aux[2*i+1]=='L')val_aux+=mat[i+1][1];
            }
          // cout<<val_aux<<'\n';

            if(val_aux>valor or vazio==0){
                vazio=1;
                valor=val_aux;
                res=mapa[{m-l,w-m,l-w}]+s;
            }
            return;
        }
        else{
            return;
        }
    }

  
    procura(elem-1,l+mat[mid+tam-elem+1][1],m+mat[mid+tam-elem+1][2],w,s+"LM");
    procura(elem-1,l+mat[mid+tam-elem+1][1],m,w+mat[mid+tam-elem+1][3],s+"LW");
    procura(elem-1,l,m+mat[mid+tam-elem+1][2],w+mat[mid+tam-elem+1][3],s+"MW");

    return;

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>mat[i][j];
        }
    }

    if(n==1){
        if(mat[1][1]==mat[1][2] and mat[1][1]==0){
            cout<<"LM"<<'\n';
        }
        else if(mat[1][2]==mat[1][3] and mat[1][2]==0){
            cout<<"MW"<<'\n';
        }
        else if(mat[1][1]==mat[1][3] and mat[1][1]==0){
            cout<<"LW"<<'\n';
        }
        else cout<<"Impossible"<<'\n';
        return 0;
    }

    mid=n/2;
    rec(mid,0,0,0,"");
    
    tam=n-mid;

    procura(tam,0,0,0,"");

    if(achou==1){
        for(int i=0;i<n;i++){
            cout<<res[2*i]<<res[2*i+1]<<'\n';
        }
    }
    else cout<<"Impossible"<<'\n';

}