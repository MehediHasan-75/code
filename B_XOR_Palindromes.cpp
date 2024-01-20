#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007;
void solve(ll tc)
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll cnt=0, od=0;
    if(n%2)od=1;
    for(ll i=0; i<n/2; i++){
        if(s[i]!=s[n-i-1])cnt++;
    }
    ll need=cnt;

    for(ll i=0; i<=n; i++){
        if(need<=i and i<=n-need){
            if(od)cout<<'1';
            else{
                if((i%2)==(cnt%2))cout<<'1';
                else cout<<'0';
            }
        }
        else cout<<'0';
    }
    cout<<endl;
}
int main()
{
    ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

