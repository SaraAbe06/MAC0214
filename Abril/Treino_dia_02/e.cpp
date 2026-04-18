//ac
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const ld G=6.67430*1e-11;
vector<ld>res;
vector<ld>x,m;
ll tot=0;

ld forca(ld m1,ld m2, ld d1,ld d2){
    ld d=d1-d2;
    return G*m1*m2/(d*d);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll n;cin>>n;
    ld mr;cin>>mr;
    for(int i=0;i<n;i++){
        ld a;cin>>a;
        x.push_back(a);
    }
    for(int i=0;i<n;i++){
        ld a;cin>>a;
        m.push_back(a);
    }
    

    cout<<fixed<<setprecision(10);

    for(int i=0;i<n-1;i++){
        ld ini=x[i],fim=x[i+1];
        ld parcial=0;
        while(fim - ini >= 1e-8){
            ld mid=ini+(fim-ini)/(ld)2.0;
            //cout<<mid<<endl;
            parcial=0.00000;
            for(int j=0;j<n;j++){
                ld d=mid-x[j];
                if(j<=i)parcial-=(G*mr*m[j])/(ld)(d*d);
                else parcial+=(G*mr*m[j])/(ld)(d*d);
            }
            //cout<<parcial<<endl;

            if(parcial>0)fim=mid;
            else ini=mid;
        }

        ini=(ini+fim)/(ld)2.0;
        if(ini==x[i] or ini==x[i+1]){
            continue;
        }
        else{
            tot++;
            res.push_back((ld)ini);
        }
    }


    cout<<tot<<'\n';
    for(int i=0;i<tot;i++)cout<<fixed<<setprecision(10)<<res[i]<<" ";
}