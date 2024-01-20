
#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 1e5 + 3, inf=2e18;
ll mod = 1000000007;
ll sq[100005];
void calc(){
    for(ll i=0; i<100005; i++)sq[i]=i*i;
}
ll func(ll n){
    ll lim=sqrt(n*1.);
    ll od=0, ev=0;
    for(ll i=2; i<=lim; i++){
        while(n%i==0){
            if(i%2==0)ev++;
            else od++;
            n/=i;
        }
    }
    if(n>1 and n%2)od++;
    else if(n>1 and n%2==0)ev++;
    if(od>0){
        if(ev==1){
            if(od>1)return 1;
            else return 0;
        }
        else return 1;
    }
    else return 0;

}
void solve(ll tc)
{
    ll n;
    cin>>n;
    if(n==2 or (n%2==1 and n!=1) or(n!=1 and func(n)))cout<<"Ashishgup\n";
    else cout<<"FastestFinger\n";
}
int main()
{
    fastio;ll T = 1;
    calc();
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

