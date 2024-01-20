
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf=2e18;
ll mod = 1000000007;
void solve(ll tc)
{
    ll n;
    cin>>n;
    vector<ll>om(n), addy(n);
    for(auto &it: om)cin>>it;
    for(auto &it: addy)cin>>it;

    ll ocnt=0, acnt=0, cnt=0;
    for(ll i=0; i<n; i++){
        cnt=0;
        while(i<n and om[i])i++, cnt++;
        ocnt=max(cnt, ocnt);
    }
    for(ll i=0; i<n; i++){
        cnt=0;
        while(i<n and addy[i])i++, cnt++;
        acnt=max(cnt, acnt);
    }
    if(acnt>ocnt){
        cout<<"Addy\n";
    }
    else if(acnt<ocnt){
        cout<<"Om\n";
    }
    else cout<<"Draw\n";
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

