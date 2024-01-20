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
    ll n, m; cin >> n >> m;

    ll matrix[n][m];
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    }
    
    ll rectangle = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {

            if (matrix[i][j] == 1)
            {
                ll mi=1e18, rows=0, col_range=m;
                for (ll k = i; k < n; k++)
                {
                    ll ones=0;
                    rows++;
                    for (ll l = j; l < col_range; l++)
                    {
                        if(matrix[k][l]==1)ones++;
                        else {
                            col_range=l;
                            break;
                        }
                    }
                    if(ones==0)break;
                    rectangle=max(rectangle, ones*rows);
                }

            }
        }
    }
    cout<<rectangle<<endl;
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

