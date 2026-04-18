#include<bits/stdc++.h>
using namespace std;

multiset<int>m;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int q;cin>>q;
    while(q--){
        int t,val;cin>>t>>val;
        if(t==1)m.insert(val);
        else{
            while(!m.empty() and *m.begin()<=val){
                int v=*m.begin();
                m.erase(v);
            }
        }

        cout<<m.size()<<'\n';
    }

}