#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn=1e5+10;
vector<ll>v;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        for(int i=0;i<n;i++){
            ll a;cin>>a;
            v.push_back(a);
        }

        ll res1=0,res2=0;
        ll v1=v[1]-v[0];
        ll flag=0;
        for(int i=1;i<n;i++){
            if(v[i]-v[i-1]!=v1){
                flag=1;
                break;
            }
        }

        if(flag==0 and v1!=0){
            res1=max(v1,(ll)(v[n-1]/v1));
        }

        for(int i=1;i<n;i++){
            if(v[i]-1>0){
                if(v[i-1]%(v[i]-1)==0){
                    // confere 
                    ll fl2=0, num=0,k1=(v[i-1]/(v[i]-1));
                    ll ind1=1,ind2=0;
                    ll it1=1,it2=k1;
                    ll meui=v[i]-1;

                    for(int j=i;j<n;j++){
                        if(v[j]!=(meui+ind1)*it1){
                            fl2=1;
                            break;
                        }
                        
                        if(it1==k1 and j!=n-1){
                            it1=1;
                            ind1++;
                        }
                        else it1++;
                    }

                    for(int j=i-1;j>=0;j--){
                        if(v[j]!=(meui-ind2)*it2){
                            fl2=1;
                            break;
                        }

                        if(it2==1 and j!=0){
                            it2=k1;
                            ind2++;
                        }
                        else it2--;
                    }

                    num=meui+ind1;

                    if(fl2==0 and (meui-ind2)>0)res2=max(res2,max(num,k1));
                }
            }
        }

        cout<<max(res1,res2)<<'\n';
        v.clear();
    }

}
