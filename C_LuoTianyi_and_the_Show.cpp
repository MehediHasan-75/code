
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
    //cout<<"Case "<<tc<<": ";
    ll n, seat;
    cin>>n>>seat;
    ll on=0, tw=0;
    vector<ll>v;
    unordered_map<ll,ll>x;
    for(ll i=0;i<n; i++){
        ll a;
        cin>>a;
        if(a==-1)on++;
        else if(a==-2)tw++;
        else {
            if(x[a]==0)v.push_back(a);
            x[a]++;
        }
    }
    sort(all(v));
    vector<ll>left(v.size()+2, 0), right(v.size()+2, 0);
    unordered_map<ll,ll>mp, mp1;
    for(ll i=0; i<v.size(); i++){
        mp[v[i]]++;
        left[i]=mp.size()-1;
    }
    for(ll i=v.size()-1; i<v.size() and i>=0; i--){
        mp1[v[i]]++;
        right[i]=mp1.size()-1;
    }
    ll mx=0;
    ll total_pos=mp.size();
    if(mp[1]!=0)total_pos--;
    mx=max(mx, min(seat, total_pos+tw));

    total_pos=mp1.size();
    if(mp1[seat]!=0)total_pos--;
    mx=max(mx, min(seat, on+total_pos));
    // // cout<<mx<<endl;
    for(ll i=0; i<v.size(); i++){
        ll left_free=v[i]-1, right_free=seat-v[i];
        //cout<<left_free<<" "<<right_free<<endl;
        ll l=min(left_free, on+i), r=min(right_free, tw+(ll)v.size()-i-1);
        mx=max(mx, l+1+r);
    }
    cout<<mx<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    //cout<<T<<endl;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

