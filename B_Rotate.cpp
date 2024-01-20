
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
    string s[n];
    ll ans[n][n];
    for(int i=0; i<n; i++)cin>>s[i];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==0){
                if(j==0)ans[i][j]=s[i+1][j]-'0';
                else ans[i][j]=s[i][j-1]-'0';
            }
            else if(i==n-1){
                if(j==n-1)ans[i][j]=s[i-1][j]-'0';
                else ans[i][j]=s[i][j+1]-'0';
            }
            else if(j==0)ans[i][j]=s[i+1][j]-'0';
            else if(j==n-1)ans[i][j]=s[i-1][j]-'0';
            else ans[i][j]=s[i][j]-'0';
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)cout<<ans[i][j];
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

