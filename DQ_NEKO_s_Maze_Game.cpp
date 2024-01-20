
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
    ll n, q;
    cin>>n>>q;

    vector<vector<ll>>arr(2, vector<ll>(n, 1));
    ll cnt=0;
    while(q--){
        ll x, y;
        cin>>x>>y;
        x--, y--;

        if(x==1 and y==n-1){
            if(arr[x][y]==0)cnt--;
            else cnt++;
            arr[x][y]=!arr[x][y];
        }
        else if(arr[x][y]==1){
            // cout<<arr[x][y];
            if(x==0){
                if(arr[x+1][y]==0)cnt++;
                if(y-1>=0 and arr[x+1][y-1]==0)cnt++;
                if(y+1<n and arr[x+1][y+1]==0)cnt++;
            }
            else{
                 if(arr[x-1][y]==0)cnt++;
                if(y-1>=0 and arr[x-1][y-1]==0)cnt++;
                if(y+1<n and arr[x-1][y+1]==0)cnt++;
            }
            arr[x][y]=0;
        }
        else{
            if(x==0){
                if(arr[x+1][y]==0)cnt--;
                if(y-1>=0 and arr[x+1][y-1]==0)cnt--;
                if(y+1<n and arr[x+1][y+1]==0)cnt--;
            }
            else{
                if(arr[x-1][y]==0)cnt--;
                if(y-1>=0 and arr[x-1][y-1]==0)cnt--;
                if(y+1<n and arr[x-1][y+1]==0)cnt--;
            }
            arr[x][y]=1;
        }
        if(cnt==0)cout << "Yes\n";
        else cout << "No\n";
    }
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

