#include<bits/stdc++.h>
using namespace std;
int main(){
    typedef long long ll;
    ll cnt=1;
    ll n;
    cin>>n;
    if(n<10)cnt=0;
    while(n>=10){
        n++;
        while((n%10)==0 and n!=0)n/=10;
        if(n>10)cnt++;
    }
    cout<<cnt+9<<endl;
}