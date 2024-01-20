
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
    vector<ll>v(n);
    char ch[n];
    for(auto &it: v)cin>>it;
    ll i=1, num=-1, last=v[0];
    cout<<1;
    for(i=1; i<n; i++){
        if(v[i]>=v[i-1])cout<<1, last=v[i];
        else{
            if(v[i]<=v[0])cout<<1, num=v[i];
            else cout<<'0';
            i++;
            break;
        }
    }
    ll found_f=0;
    for(; i<n; i++){
        if(v[i]<=v[0] and v[i]>=num){
            num=v[i];
            cout<<1;
        }
        else if(num==-1 and v[i]>=last)cout<<1, last=v[i];
        else cout<<'0';
    }
    cout<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

