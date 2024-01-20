#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10, Log=18;

#define ll long long
#define endl '\n'
ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
  return (a / gcd(a, b)) * b;
}

ll spharse1[Log][N], spharse2[Log][N];
vector<ll>v(N);

void spharseTable(ll n){
    copy(v.begin(), v.begin()+n, spharse1[0]);
    copy(v.begin(), v.begin()+n, spharse2[0]);

    for (ll i = 1; i < Log; i++)
    {
        for (ll j = 0; j + (1ll << i) <= n; j++)
        {
            spharse1[i][j] = gcd(spharse1[i - 1][j], spharse1[i - 1][j + (1 << (i - 1))]);
            spharse2[i][j] = lcm(spharse2[i - 1][j], spharse2[i - 1][j + (1 << (i - 1))]);
            if(spharse2[i][j]>10000000)spharse2[i][j]=0;
        }
    }
}

ll rangeGcd(ll l, ll r)
{
    ll len = r - l + 1, i = (ll)log2(len);
    return gcd(spharse1[i][l], spharse1[i][r - (1 << i)+1 ]);
}

ll rangeLcm(ll l, ll r)
{
    ll len = r - l + 1, i = (ll)log2(len);
    return lcm(spharse2[i][l], spharse2[i][r - (1 << i)+1 ]);
}
ll lower(ll st, ll en, ll k, ll n){
    ll hi=en, lo=st, ans=n;

    while(hi>=lo){
        ll mid=(hi+lo)/2;

        ll gc=rangeGcd(st, mid), lc=rangeLcm(st, mid);

        if(lc<=0 or lc>=k*gc){
            hi=mid-1;
            ans=mid;
        }
        else{
            lo=mid+1;
        }
    }
    return ans;
}
ll upper(ll st, ll en, ll k, ll n){
    ll hi=en, lo=st, ans=n;

    while(hi>=lo){
        ll mid=(hi+lo)>>1;

        ll gc=rangeGcd(st, mid), lc=rangeLcm(st, mid);

        if(lc<=0 or lc>k*gc){
            hi=mid-1;
            ans=mid;
        }
        else{
            lo=mid+1;
        }
    }
    return ans;
}
void solve(){
    ll n, k;
    cin>>n>>k;
    for(ll i=0; i<n; i++)cin>>v[i];
    spharseTable(n);
    ll ans=0;

    for(ll i=0; i<n; i++){
        ll lowerbound=lower(i, n-1, k, n);
        ll upperbound=upper(i, n-1, k, n);

        ans+=upperbound-lowerbound;
        // cout<<lowerbound<<endl;
    }
    cout<<ans<<endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--)solve();
}