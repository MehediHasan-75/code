
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
    ll n;
    cin>>n;
    vector<ll>divi(n+1, 0);
    for(ll i=1; i*i<=n; i++)if(n%i==0){
        divi[i]=divi[n/i]=1;
    }
    ll prev= 0, nai=n;
    for(ll i=1; i<=26; i++){
        if(divi[i]==0){
            nai=i;
            break;
        }
    }
    string st="";
    for(ll i=0; i<nai; i++)st+=(char)(i+'a');
    
    ll rep=(n/nai), extra=n%nai;
    while(rep--)cout<<st;
    for(ll i=0; i<extra; i++)cout<<(char)(i+'a');
    cout<<endl;
    
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

