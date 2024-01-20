
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
vector<ll>pr={ 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
void solve(ll tc)
{
    string s;
    cin>>s;
    for(ll i=0; i<pr.size(); i++){
        ll fl=1;
        for(auto &it: s){
            if(fl)
            if(it-'0'==pr[i]/10){
                fl=0;
            }
            if(!fl){
                if(it-'0'==pr[i]%10){
                    cout<<pr[i]<<endl;
                    return;
                }
            }
        }
    }
    cout<<-1<<endl;
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

