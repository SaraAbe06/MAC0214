#include<bits/stdc++.h>
using namespace std;

map<string,int>m;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        m[s]++;
    }

    int maior=0;
    string rei;
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second>maior){
            maior=it->second;
            rei=it->first;
        }
    }

    cout<<rei;
}
