#include<bits/stdc++.h>
using namespace std;

#define    ll      long long
#define    pii     pair<int,int>
#define    vii     vector<int>
#define    vcc     vector<char>
#define    pll     pair<long long, long long>
#define    mem     memset
#define    sof     sizeof
#define    co1     __builtin_popcountll
#define    PB      push_back
#define    UB      upper_bound
#define    LB      lower_bound
#define    MP      make_pair
#define    TS      to_string
#define    F       first
#define    S       second
#define    pi      acos(-1)
#define    mod     (long long)1000000007
#define    inf     (long long)1e18
#define    endl    '\n'

ll n, k;
string s;

ll dp[10][90][90][2];

ll DP(ll i, ll sum, ll rem, ll st) {
    if(i==n) {
        if(sum==0 && rem==0) return 1;
        return 0;
    }
    ll &ans = dp[i][sum][rem][st];
    if(ans != -1) return ans;
    ans = 0;
    ll tar;
    if(st) tar = 9;
    else tar = s[i]-'0';
    for(ll ii=0; ii<=tar; ii++) {
        ans += DP(i+1, (sum+ii)%k, (rem*10+ii)%k, st | (ii<s[i]-'0'));
    } 
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1, T=0;
    cin>>t;
    while(t--){
        long long a,b,c,d,e,f,i,j,m,o,x,y;
        cout << "Case " << ++T << ": ";
        ll l, r;
        cin >> l >> r >> k;
        if(k > 90) {
            cout << 0 << "\n";
            continue;
        }
        l--;
        memset(dp, -1, sizeof(dp));
        s = to_string(r);
        n = s.size();
        ll ans = DP(0, 0, 0, 0);
        s = to_string(l);
        n = s.size();
        memset(dp, -1, sizeof(dp));
        ans -= DP(0, 0, 0, 0);
        cout << ans << "\n";
    }
}
