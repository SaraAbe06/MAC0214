#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll d[1010];
vector<ll>v;
ll R,N;

ll confere(){
    ll posi=-1;
    ll mflag=0;

    for(int i=0;i<v.size();i++){
        ll ini=v[i];
        //cout<<ini<<" ";
        for(int j=0;j<N;j++){
            ll val=d[j];
          //  cout<<"rr"<<val<<"bb"<<endl;

            if(ini+val<0)ini=0;
            else if(ini+val>R)ini=R;
            else ini=ini+val;

          //  cout<<"aaa"<<j<<" "<<ini<<endl;
        }

        //cout<<ini<<" ";
        if(i==0)posi=ini;
        else{
            if(posi!=ini){
                mflag=1;
                break;
            }
        }
    }

    if(mflag)return -1;
    else return posi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   cin>>R>>N;
    for(int i=0;i<N;i++)cin>>d[i];
   // for(int i=0;i<N;i++)cout<<d[i]<<" ";
    
    ll ini=0,fim=R;
    ll rx=0, ry=R;
    ll flag=0;

    if(R==1){
        v.push_back(0);
        v.push_back(1);
        
        ll valor=confere();
        if(valor==-1)cout<<"uncertain"<<'\n';
        else cout<<valor<<'\n';
    }
    else if(R==2){
        v.push_back(0);
        v.push_back(1);
        v.push_back(2);

        ll valor=confere();
        if(valor==-1)cout<<"uncertain"<<'\n';
        else cout<<valor<<'\n';
    }
    else{
        ini=1,fim=R-1;
        rx=1,ry=R-1;
        v.push_back(0);
        v.push_back(R);

        for(int i=0;i<N;i++){
            ll val=d[i];
            ll nx=rx+val,ny=ry+val;
            if(d[i]==0)continue;

            if(ini==fim){
                v.push_back(ini);
                flag=1;
                break;
            }

            if(nx<=0 and ny<=0){
                v.push_back(ini);
                flag=1;
                break;
            }
            else if(nx>=R and ny>=R){
                v.push_back(ini);
                flag=1;
                break;
            }
            else if(nx<=0 and ny<=R){
                v.push_back(ini);
                ini=1+(ini-nx);
                
                rx=1;
                ry=ny;
                fim+=val;
            }
            else if(nx<=R and ny>R){
                fim=fim-(ny-99);
                v.push_back(fim+1);

                rx=nx;
                ry=R-1;
                ini+=val;
                
            }
            else{
                rx+=val;
                ry+=val;
                
                ini+=val;
                fim+=val;
            }

        }

        if(flag==1){
            ll valor=confere();
            if(valor==-1)cout<<"uncertain"<<'\n';
            else cout<<valor<<'\n';
        }
        else cout<<"uncertain"<<'\n';
    }
    
}
