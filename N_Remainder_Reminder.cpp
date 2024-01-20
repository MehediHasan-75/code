#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n, k;
    cin>>n>>k;
    long long cnt=0;
    for(long long b=k+1; b<=n; b++){
        cnt+=((n+1)/b)*(b-k)+max(0ll, ((n+1)%b)-k);
    }
    if(k==0)cnt-=n;
    cout<<cnt<<endl;
}