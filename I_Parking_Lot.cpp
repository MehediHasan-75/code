#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll space=2*n-2, rem=space-n,ways=0;
    //cout<<rem<<endl;
    for(int i=0; i<=rem; i++){
        ll cnt=n-1, temp=4;
        for(int j=i-1; j>=0; j--){
            ++cnt;
            if(cnt==n)temp*=3, cnt=0;
            else temp*=4;
        }
        cnt=n-1;
        for(int j=i+1; j<=rem; j++){
            ++cnt;
            if(cnt==n)temp*=3, cnt=0;
            else temp*=4;
        }
        //cout<<temp<<endl;
        ways+=temp;
    }
    cout<<ways<<endl;
}