
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 105, inf=2e18;
ll mod = 1000000007;
ll n, s;
ll head[N], tell[N];
bool fl=0;
string ans="";
string st;
ll dp[10001][101];
void func(ll sum, ll ind){
    if(ind==n and sum==s){
        fl=1;
        ans=st;
        return;
    }
    if(ind==n)return;
    if(dp[sum][ind])return ;
    st.push_back('H');
    func(sum+head[ind], ind+1);
    st.pop_back();
    st.push_back('T');
    func(sum+tell[ind], ind+1);
    st.pop_back();
    dp[sum][ind]=1;
    return;
}
void solve(ll tc)
{
    cin>>n>>s;
    for(ll i=0; i<n; i++){
        ll a, b;
        cin>>a>>b;
        head[i]=a;
        tell[i]=b;
    }
    st.push_back('H');
    func(head[0], 1);
    st.pop_back();
    st.push_back('T');
    func(tell[0], 1);
    if(fl){
        cout << "Yes\n";
        cout<<ans<<endl;
    }
    else cout << "No\n";
}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

