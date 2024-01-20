
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
    string s;
    cin>>s;
    vector<ll>v[10];
    ll m;
    cin>>m;
    string l, r;
    cin>>l>>r;
    ll ind=0;
    for(ll i=0; i<m; i++){
        ll mx1=-1;
        for(ll j=l[i]-'0'; j<=r[i]-'0'; j++){
            //cout<<j<<" ";
            ll mx=-1;
            for(ll k=ind; k<s.size(); k++){
                if(s[k]-'0'==j){
                    mx=max(mx, k);
                    break;
                }
            }
            //cout<<mx<<endl;
            if(mx==-1){
            cout<<"YES\n";
            return;
            }
            else mx1=max(mx1, mx);

        }
        //cout<<endl;
        ind=mx1+1;
        //cout<<"ind = "<<ind<<endl;
    }
    cout<<"NO\n";
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

