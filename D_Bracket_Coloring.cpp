
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
    string s;
    cin>>s;

    ll balance=0;
    for(auto &it: s){
        if(it==')')balance--;
        else balance++;
    }

    if(balance!=0){
        cout<<-1<<endl;
        return;
    }
    stack<ll>st;
    bool fl=true;
    vector<ll>ans(n, 0);
    for(ll i=0; i<n; i++){
        if(s[i]=='('){
            st.push(i);
        }
        else{
            if(st.size()==0){
                fl=false;
                continue;
            }
            else{
                ll ind1=st.top();
                st.pop();
                ans[i]=ans[ind1]=1;
            }
        }
    }
    if(fl){
        cout<<1<<endl;
        prnt(ans);
    }
    else{
        ans.assign(n, 2);
        stack<ll>st1;
        for(ll i=n-1; i>=0; i--){
        if(s[i]=='('){
            st1.push(i);
        }
        else{
            if(st1.size()==0){
                fl=false;
                continue;
            }
            else{
                ll ind1=st1.top();
                st1.pop();
                ans[i]=ans[ind1]=1;
            }
        }
    }
    cout<<*max_element(all(ans))<<endl;
    prnt(ans);
    }
}
int main()
{
    fastio;ll T = 1;
    cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

