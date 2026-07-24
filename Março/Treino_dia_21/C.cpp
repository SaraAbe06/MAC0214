#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>par;

const ll maxn=1e3+10;

char m[maxn][maxn];
ll visi[maxn][maxn];
queue<par>q;
ll h,w;

ll li[4]={0,0,1,-1};
ll col[4]={1,-1,0,0};

par bfs(ll x,ll y){
    q.push({x,y});
    ll flag=0;
    ll tam=0;

    if(x==1 or x==h or y==1 or y==w)flag=1;

    while(!q.empty()){
        ll myx=q.front().first;
        ll myy=q.front().second;

        q.pop();

        if(visi[myx][myy])continue;
        visi[myx][myy]=1;

        for(int i=0;i<4;i++){
            ll nx=myx+li[i];
            ll ny=myy+col[i];

            if(nx>=1 and nx<=h and ny>=1 and ny<=w){
                if(m[nx][ny]=='.'){
                    q.push({nx,ny});
                    if(nx==1 or ny==1 or nx==h or ny==w)flag=1;
                }
            }
        }
    }

    return {flag,0};
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>h>>w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>m[i][j];
        }
    }

    ll qtd=0;
   for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
           if(visi[i][j]==0 and m[i][j]=='.'){
                par a=bfs(i,j);
                if(a.first==0)qtd++;
           }
        }
    }

    cout<<qtd<<'\n';
   
}
