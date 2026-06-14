#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[5050],b[5050],c[5050];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        for(int i=1;i<=n;i++)cin>>c[i];

        ll qtd1=0,qtd2=0;
        for(int i=1;i<=n;i++){
            ll ind=i;
            ll flag=0;
            for(int j=1;j<=n;j++){
                if(b[j]<=a[ind]){
                    flag=1;
                    break;
                }
                ind++;
                if(ind>n)ind=1;
            }
            if(flag==0)qtd1++;
        }

        for(int i=1;i<=n;i++){
            ll ind=i;
            ll flag=0;
            for(int j=1;j<=n;j++){
                if(b[j]>=c[ind]){
                    flag=1;
                    break;
                }
                ind++;
                if(ind>n)ind=1;
            }
            if(flag==0)qtd2++;
        }

        cout<<qtd1*qtd2*n<<'\n';
    }
}