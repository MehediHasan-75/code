
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
    string s;
    cin>>s;
    if(s=="()"){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        string a1(s.length(), '(');
        a1+=string(s.length(), ')');
        string a2="";
        for(ll i=0; i<s.length(); i++){
            a2+="()";
        }
        for(ll i=0; i<a1.size()-s.size()+1; i++)
        {
            string r = a1.substr(i, s.size());
            if(r==s){
                cout<<a2<<endl;
                return;
            }
        }
        cout<<a1<<endl;
    }
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

