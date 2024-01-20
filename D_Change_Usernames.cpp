
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
map<ll, vector<ll>>graph;
// vector<ll>graph[20000000];
map<ll, ll>in_degree;
vector<int> ans;
set<int> st;
int cnt = 0;
void bfs()
{
    while(!st.empty())
    {
        cnt++;
        int u = *st.begin();
        st.erase(st.begin());
        ans.push_back(u);
        vector<int> temp;
        for(auto &it: graph[u])
        {
            in_degree[it]--;
            if(!in_degree[it])
            {
                st.insert(it);
            }
        }
    }
}
ll func(string s){
    ll num=0;
    for(ll i=0; i<s.size(); i++){
        num=num*26+ s[i]-'a'+1;
    }
    return num;
}
void solve(ll tc)
{
    ll e;
    cin>>e;
    set<ll>nodes;
    for(ll i=0; i<e; i++){
        string st1, st2;
        cin>>st1>>st2;
        ll u=func(st1), v=func(st2);
        graph[u].push_back(v);
        in_degree[v]++;
        nodes.insert(u);
        nodes.insert(v);
    }
    for(auto &it: nodes){
        if(in_degree[it]==0){
            st.insert(it);
        }
    }
    bfs();
    // cout<<cnt<<endl;
    if(cnt==nodes.size())cout << "Yes\n";
    else cout << "No\n";
    // cout<<func("zzzzzzzz");
}
int main()
{
    fastio;ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

