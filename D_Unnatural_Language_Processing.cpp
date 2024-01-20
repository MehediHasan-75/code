
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
bool vow(char ch){
    return ch=='a' or ch=='e';
}
void solve(ll tc)
{
   ll n;
   cin>>n;

   string s;
   cin>>s;

   for(ll i=0; i<n; i++){
    if(vow(s[i])){
        cout<<s[i];
        if(i+2<n and !vow(s[i+2])){
            cout<<s[i+1];
            i++;
        }
        if(i<n-2)cout<<'.';
    }
    else cout<<s[i];
   }
   cout<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

