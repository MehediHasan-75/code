#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    ll n, m, r;
    cin>>n>>m>>r;

    ll mi1=INT64_MAX, mi2=mi1, mi3=mi1, s1=0, s2=0, s3=0;


    for(ll i=0; i<n; i++){
        ll a;
        cin>>a;
        mi1=min(a, mi1);
        s1+=a;
    }
    for(ll i=0; i<m; i++){
        ll a;
        cin>>a;

        mi2=min(a, mi2);
        s2+=a;
    }
    for(ll i=0; i<r; i++){
        ll a;
        cin>>a;

        mi3=min(a, mi3);
        s3+=a;
    }

    cout<<(s1+s2+s3) - 2* min({s1, s2, s3, mi1+mi2, mi1+mi3, mi2+mi3});
}