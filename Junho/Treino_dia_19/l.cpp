#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>s,b;

ll flag=0;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll n,m,x,y;cin>>n>>m>>x>>y;
    for(int i=0;i<n;i++){
        ll aa;cin>>aa;
        s.push_back(aa);
    }
    for(int i=0;i<m;i++){
        ll aa;cin>>aa;
        b.push_back(aa);
    }

    sort(s.begin(),s.end());
    sort(b.begin(),b.end());

    ll num=0,prat=0,tot=0;
    for(int i=0;i<m;i++){
        if(b[i]<=s[prat]){
            num++;
        }
        else{
            while(b[i]>s[prat] and prat<n)prat++;
            if(prat==n)break;
            else{
                num=1;
            }
        }

        tot++;
        if(num==x){
            prat++;
            num=0;
        }

        if(prat>=n)break;
    }

    if(tot!=m){
        cout<<"impossible\n";
        return 0;
    }

    ll ini=0,fim=n;
    while(ini<fim){
        ll mid=(ini+fim)/2;
        if(ini==fim-1)mid=fim;

        int ind=0,sum=0;
        for(int i=0;i<n;i++){
            if(i<mid){
                ll tot=0;
                while(ind<m and tot<y){
                    if(b[ind]<=s[i]){
                        tot++;
                        ind++;
                        sum++;
                    }
                    else break;
                }

               // cout<<i<<" "<<tot<<endl;
            }
            else{
                ll tot=0;
                while(ind<m and tot<x){
                    if(b[ind]<=s[i]){
                        tot++;
                        ind++;
                        sum++;
                    }
                    else break;
                }

               // cout<<i<<" "<<tot<<endl;

            }
        }
       // cout<<ini<<" "<<fim<<" "<<mid<<" "<<sum<<endl;

        if(sum==m)ini=mid;
        else fim=mid-1;
    }

    cout<<ini<<endl;
}
