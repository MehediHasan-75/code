#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
double eps = 1e-12;
#define precision(n) cout << setprecision(n) << fixed;
typedef long double ld;
void solve(){
    ld d, l;
    cin>>d>>l;

    ld a=(l/2), b=sqrt((l*l-d*d)/4);
    precision(3);
    cout<<pi*a*b<<"\n";
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}