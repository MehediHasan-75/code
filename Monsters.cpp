
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 1e6 + 10, inf=2e18;
ll mod = 1000000007;
vector<ll> primes;
vector<ll> mark(N,0);
void siv()
{
    mark[1]=1;
    for(ll i=4; i<=N; i+=2)mark[i]=1;
   /*Every number will have a divisor which will be equal or less then sqrt(num).
   Their divisors<=sqrt(num) will  mark them automatically as composite number*/
    for(ll i=3; i*i<=N; i+=2)
    {
        if(!mark[i])for(ll j=i*i; j<=N; j+=i+i)mark[j]=1;
    }
    primes.push_back(2);
    for(ll i=3; i<=N; i+=2)if(!mark[i])primes.push_back(i);
    
}

void solve(ll tc)
{
    ll n;
    cin>>n;

    ll cnt=0, fl=1;

    while(n){
        if(n<0){
            cout<<-1<<endl;
            return;
        }
        if(!mark[n] and fl){
            cout<<cnt+1<<endl;
            return;
        }
        if(n-(1ll<<cnt))
        n-=(1ll<<cnt);
        cnt++;
    }
    cnt--;
    cout<<cnt<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    siv();
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

