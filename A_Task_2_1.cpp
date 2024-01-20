#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main(){
    ll n, m, l, r;
    cin>>n>>m>>l>>r;
    ll gc=__gcd(n, m);
    double lc= (1.*(1.*n/gc)*m);
    cout<<(ll)(1.*r/lc)-(ll)(1.*(l-1)/lc);
}
/*01000010 01100001 01101100 01100101 01110010 00100000 01110000 01110010 01101111 01100010 01100101 01101100 01101101 00101110 00100000 01010100 01101000 01100101 00100000 01110111 01101111 01110010 01110011 01110100 00100000 01110000 01110010 01101111 01100010 01101100 01100101 01101101 00100000 01101001 01101110 00100000 01101101 01111001 00100000 01101100 01101001 01100110 01100101 00101110*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define sz(x) (ll)x.size()
// #define PI      acos(-1.0)
// #define all(x) x.begin(),x.end()
// #define endl  "\n"
// const ll mod = 1000000007;

// void solve(){
//     ll n,m,l,r;
//     cin>>n>>m>>l>>r;
//     ll gc = __gcd(n,m);
//     double lcm = 1.0*(1.0*n/gc)*m;
//     ll x,y;
//     x=(l-1)/lcm;
//     y=r/lcm;
//     cout<<y-x<<endl;

// }


// int main()
// {
//     faster
//     solve();
// }