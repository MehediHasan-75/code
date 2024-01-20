#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
double eps = 1e-12;
#define precision(n) cout << setprecision(n) << fixed;
typedef long double ld;
int main(){
    ll n, a, b;
    cin>>n>>a>>b;
    vector<ll>v(n);
    for(auto &it: v)cin>>it;
    sort(v.begin(), v.end(), greater<ll>());

    long double mean=0, sm=0, cnt=a;
    for(ll i=0; i<a; i++)sm+=(v[i]*1.);

    mean=sm/cnt;
    // cout<<mean<<" "<<cnt<<" "<<sm<<endl;
    for(ll i=a; i<b; i++){
        cnt++;
        sm+=(v[i]*1.);
        mean=max(mean, sm/cnt);
    }
    precision(6);
    cout<<mean<<endl;
}