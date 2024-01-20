
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

ll dist(ll x1, ll y1, ll x2, ll y2){
    return abs(x1-x2)+abs(y1-y2);
}
void solve(ll tc)
{
    ll x, y;

    cin>>x>>y;

    for(ll i=0; i<51; i++){
        for(ll j=0; j<51; j++){
            if(2*dist(0, 0, i, j)==dist(0, 0, x, y) and 2*dist(x, y, i, j)==dist(0, 0, x, y)){
                cout<<i<<" "<<j<<endl;
                return;
            }
        }
    }
    cout<<-1<<" "<<-1<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

