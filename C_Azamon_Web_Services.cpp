
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
    string s1, s2;
    cin>>s1>>s2;
    ll lim=min(s1.size(), s2.size());
    for(ll i=0; i<lim; i++){
        ll swap_ind=i;
        for(ll j=s1.size()-1; j>i; j--){
            if(s1[j]<s1[swap_ind]){
                swap_ind=j;
            }
        }
        if(swap_ind==i)continue;
        else{
            swap(s1[i], s1[swap_ind]);
            break;
        }
    }
    if(s1<s2)cout<<s1<<endl;
    else cout<<"---\n";
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

