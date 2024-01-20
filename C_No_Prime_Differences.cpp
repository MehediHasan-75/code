
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
    ll cnt=1;
    ll arr[n][m];
    memset(arr, 0, sizeof(arr));
    if(m%2==0){
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                arr[i][j]=cnt++;
            }
        }
    }
    else if(n%2==0){
        for(ll j=0; j<m; j++){
            for(ll i=0; i<n; i++){
                arr[i][j]=cnt++ ;
            }
        }
    }
    else{
        ll row=n/2;
        for(ll i=0; i<m; i++)arr[row][i]=cnt++ ;
        for(ll i=0; i<n/2; i++){
            for(ll j=0; j<m; j++){
                arr[i][j]= cnt++;
            }
            ll down=n-i-1;
            for(ll j=0; j<m; j++){
                arr[down][j]=cnt++;
            }
        }

    }
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
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

