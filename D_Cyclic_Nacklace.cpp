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
char s[100001];
ll pi_func(char s[]){
    //cout<<s<<"\n";
    ll n=strlen(s),mx=0;
    vector<ll>pi(n,0);
    for(ll i=1; i<n; i++){
        ll j=pi[i-1];
        while(j>0 and s[j]!=s[i])j=pi[j-1];
        if(s[i]==s[j])j++;
        mx=max(mx, j);
        pi[i]=j;
    }
    //cout<<mx<<endl;
    return pi[n-1];
}
void solve(ll tc)
{
    
    cin >> s;
    ll n=strlen(s);
    ll segment=n-pi_func(s);
    //cout<<n<<"___\n";
    //cout<<segment<<"  ";
    if(segment == n){
        cout<<n<<"\n";
        return;
    }
    if(n%segment==0 and n!=segment)cout<<0<<endl;
    else{
        cout<<segment-(n%segment)<<endl;
    }
    //cout<<segment<<endl;
    // cout<<max(0ll, (ll)s.size()-pi_func(s)*2)<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

