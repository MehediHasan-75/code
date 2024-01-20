#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool func(ll n, ll m){
    vector<ll>mrk(n+1, 0);
    mrk[1]=1;
    ll x=1, cnt=0, unmrk=n-1;
    while(1){
        cnt++;
        x+=m;
        if(x>n)x=x%n;
        if(!mrk[x])unmrk--;
        mrk[x]=1;
        cout<<x<<" ";
        if(unmrk==0 and x==13)return true;
        if(cnt>n*n or (mrk[13]==1 and unmrk))return false;
    }
}
int main(){
    while(1){
        ll n;
        cin>>n;
        if(n==0)break;
        // for(ll i=2; ; i++){
        //     if(func(n,i)){
        //         cout<<i<<endl;
        //         break;
        //     }
        // }
        cout<<func(n,7);
    }
}