#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

ll ehNum(char a){
    int k=(int)a;
    if(a>=97 and a<=122)return 0;
    else return 1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    while(n--){
        string s;cin>>s;
        int temL=0, temN=0;
        int ultN=0,ultL=0;
        int flag=0;
    
        if(s.size()<=10) cout<<"N"<<'\n';
        else{
            for(int i=0;i<s.size();i++){
                ll res=ehNum(s[i]);
              //  cout<<s[i]<<" "<<(int)s[i]<<" "<<res<<endl;
                if(res==1){
                    if(temL){
                        flag=1;
                        break;
                    }
                    else if(temN==0){
                        ultN=(int)s[i];
                        temN=1;
                    }
                    else{
                        if(ultN>(int)s[i]){
                            flag=1;
                            break;
                        }
                        else{
                            ultN=(int)s[i];
                        }
                    }
                }
                else{
                    if(temL==0){
                        ultL=(int)s[i];
                        temL=1;
                    }
                    else{
                        if(ultL>(int)s[i]){
                            flag=1;
                            break;
                        }
                        else{
                            ultL=(int)s[i];
                        }
                    }

                }
            }

            if(flag==1 or temL==0 or temN==0)cout<<"N"<<'\n';
            else cout<<"S"<<'\n';
        }
       
    }
    
   
}