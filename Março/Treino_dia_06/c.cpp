#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> par;

const ll maxn=1e3+4;

ll x1,meuy1,x2,y2;
ll mlin[maxn][maxn];
ll mcol[maxn][maxn];

ll li[4]={1,-1,0,0};
ll col[4]={0,0,1,-1};

ll m[maxn][maxn];
ll tam=0;

// void imprime() {
//     for(int i=0; i<10; i++) {
//         for(int j=0; j<10; j++) cout << m[i][j];
//         cout << "\n";
//     }
// }
void bfs(ll x,ll y){
    queue<par>q;
    q.push({x,y});

    ll conta=0;

    while(!q.empty()){
        ll atx=q.front().first;
        ll aty=q.front().second;

        q.pop();
        if(m[atx][aty]==1) continue;
        m[atx][aty]=1;

        conta++;

        for(int i=0;i<4;i++){
            ll nx=atx+li[i];
            ll ny=aty+col[i];

            if(nx>=0 and nx<1000 and ny>=0 and ny<1000){
                if(m[nx][ny]==0){
                    if(li[i]==0){
                        if(col[i]==1){
                            if(mcol[atx][aty+1]==0)q.push({nx,ny});
                        }
                        else{
                            if(mcol[atx][aty]==0)q.push({nx,ny});
                        }
                    }
                    else{
                        if(li[i]==1){
                            if(mlin[atx+1][aty]==0)q.push({nx,ny});
                        }
                        else{
                            if(mlin[atx][aty]==0)q.push({nx,ny});
                        }
                    }
                }
            }
        }
    }

    
    if((x>0 or y>0))tam=max(conta,tam);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;cin>>n;
    ll x0,y0;cin>>x0>>y0;

    x1=x0,meuy1=y0;
    for(int i=0;i<n;i++){
        cin>>x2>>y2;
        if(x1==x2){
            for(int j=min(meuy1,y2);j<max(y2,meuy1);j++){
                mlin[x1][j]=1;
            }
        }
        else{
            for(int j=min(x1,x2);j<max(x1,x2);j++){
                mcol[j][meuy1]=1;
            }
        }

        x1=x2,meuy1=y2;
    }

    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            if(m[i][j]==0){
                bfs(i,j);
                // cout << i << " " << j << " - " << tam << "\n";
                // imprime();
            }
        }
    }
    
    cout<<tam<<'\n';
}

