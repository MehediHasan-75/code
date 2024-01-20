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
    // cout<<s[0]<<endl;
    ll n=s.size(), last_sorted=1;
    stack<ll>st;
    for(ll i=1; i<=n; i++){
        // cout<<"HI\n";
        if(s[i-1]=='+'){
            if(st.size() and st.top()<0){
                st.push(-i);
            }
            else st.push(i);
        }
        else if(s[i-1]=='-'){
            st.pop();
        }
        else if(s[i-1]=='1'){
            if(st.size()>1 and st.top()<0){
                cout << "NO\n";
                return;
            }
            last_sorted=i;
        }
        else{
            if(st.size()<2 or st.top()<=last_sorted and st.top()>0){
                cout << "NO\n";
                return;
            }
            else{
                if(st.top()>0){
                    ll num=st.top();
                    st.pop();
                    st.push(-num);
                    last_sorted=num-1;
                    
                }
            }
        }
    }
    cout << "YES\n";
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}