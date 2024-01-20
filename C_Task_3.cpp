
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

bool cmp(string s1, string s2){
    if(s1.length()==s2.length()){
        return s1<s2;
    }
    else return s1.length()<s2.length();
}
void solve(ll tc)
{
    ll n;
    cin>>n;

    vector<string>v(n);
    for(ll i=0; i<n; i++)cin>>v[i];

    sort(v.begin(), v.end(), cmp);
    bool fl=1;

    for(ll i=1; i<n; i++){
        if (v[i].find(v[i-1]) == string::npos){
            fl=0;
            break;
        }
    }
    // for(ll i=0; i<n; i++)cout<<v[i]<<endl;
    if(!fl){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(ll i=0; i<n; i++)cout<<v[i]<<endl;
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

