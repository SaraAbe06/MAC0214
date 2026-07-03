#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll n;cin>>n;
    
    for(int i=0;i<n;i++)cout<<" ";
    for(int i=0;i<n+1;i++)cout<<"_";
    
    cout<<endl;

    ll ind=n-1,interno=n+1;
    for(int j=0;j<n-1;j++){
        for(int i=0;i<ind;i++)cout<<" ";
        cout<<"/";
        for(int i=0;i<interno;i++)cout<<" ";
        cout<<"\\";

        ind--;
        interno+=2;
        cout<<endl;
    }

    cout<<"/";
    for(int i=0;i<n;i++)cout<<"_";
    for(int i=0;i<interno-n;i++)cout<<" ";
    cout<<"\\";
    for(int i=0;i<n+1;i++)cout<<"_";

    cout<<endl;

    ind=n+1,interno=3*n-1;
    for(int j=0;j<n-1;j++){
        for(int i=0;i<ind;i++)cout<<" ";
        cout<<"\\";
        for(int i=0;i<interno;i++)cout<<" ";
        cout<<"/";

        ind++;
        interno-=2;
        cout<<endl;
    }

    for(int i=0;i<ind;i++)cout<<" ";
    cout<<"\\";
    for(int i=0;i<interno;i++)cout<<"_";
    cout<<"/";




}
