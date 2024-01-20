
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define prnt(x)            \
    for (auto &it : x)     \
        cout << it << " "; \
    cout << "\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf = 2e18;
ll mod = 1000000007;
void solve(ll tc)
{
    string s;
    cin >> s;
    s = '0' + s;
    ll ind = s.size(), i=s.size()-1;
    if (s[i] == '9')
    {
        while (s[i] == '9')
            s[i] = '0', i--;
        // cout<<i<<" ";
        s[i] = (char)((s[i] - '0' + 1) + '0');
        ind = i+1;
    }
    if(i==s.size()-1)i--;
    for (; i >= 0; i--)
    {
        if (s[i] == '9')
        {
            while (s[i] == '9')
                s[i] = '0', i--;
            // cout<<i<<" ";
            s[i] = (char)((s[i] - '0' + 1) + '0');
            ind = i+1;
        }
        if (s[i+1]>='5'){
            ind=i+1;
            s[i]=(s[i]-'0')+1+'0';
        }
    }
    //cout<<s<<" "<<ind<<endl;
    if(s[0]!='0')cout<<s[0];
    ll j=1;
    for(; j<ind; j++)cout<<s[j];
   // cout << s << endl;
    for(; j<s.size(); j++)cout<<'0';
    cout<<endl;
}
int main()
{
    fastio;
    ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)
        solve(i);
    return 0;
}
