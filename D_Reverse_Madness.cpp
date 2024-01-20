
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
    ll n, m;
    cin>>n>>m;

    string s;
    cin>>s;
    vector<ll>l(m), r(m);
    for(auto &it: l)cin>>it, it--;
    for(auto &it: r)cin>>it, it--;

    // prnt(l);
    // prnt(r);
    ll q;
    cin>>q;
    vector<ll>cnt(n, 0);
    for(ll i=0; i<q; i++){
        ll a;
        cin>>a;
        a--;
        cnt[a]++;
    }
    string ans="";
    for(ll i=0; i<m; i++){
        ll st=l[i], en=r[i], op=0;
        for(ll i=st; i<=en; i++){
            if(cnt[i]){
                op=i;
                break;
            }
        }
        cout<<st<<" "<<en<<" "<<op<<endl;
        cout<<s<<endl;
        reverse(s.begin()+op, s.begin()+st+en-op+1);
        cout<<s<<endl;
    }
    cout<<s<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

