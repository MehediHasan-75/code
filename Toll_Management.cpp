#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=1e5+10;
vector<pair<ll,ll>> graph1[N], graph2[N];
vector<ll>dist1(N, 1e18), dist2(N, 1e18), midist1(N, -1), midist2(N, -1);
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll n, m, s, d, p;

void dijkstra1(ll source){

    for(ll i=0; i<=n; i++)dist1[i]=1e18;
    set<pair<ll,ll>>st;
    dist1[source]=0;
    st.insert({source, 0});
    while(st.size()){
        auto it=st.begin();
        ll u=(*it).first, w=(*it).second;
        st.erase(st.begin());

        if(dist1[u]<w)continue;
        for(auto &it: graph1[u]){
            ll v=it.first, w=it.second;
            if(dist1[v]>dist1[u]+w){
                dist1[v]=dist1[u]+w;
                st.insert({v, dist1[v]});
            }
        }
    }
}

void dijkstra2(ll source){

    for(ll i=0; i<=n; i++)dist2[i]=1e18;
    set<pair<ll,ll>>st;
    dist2[source]=0;
    st.insert({source, 0});
    while(st.size()){
        auto it=st.begin();
        ll u=(*it).first, w=(*it).second;
        st.erase(st.begin());

        if(dist2[u]<w)continue;
        for(auto &it: graph2[u]){
            ll v=it.first, w=it.second;
            if(dist2[v]>dist2[u]+w){
                dist2[v]=dist2[u]+w;
                st.insert({v, dist2[v]});
            }
        }
    }
}
void solve(ll tc){
    cout<<"Case "<<tc<<": ";
    cin>>n>>m>>s>>d>>p;

    for(ll i=0; i<=n; i++)graph1[i].clear(), graph2[i].clear();

    for(ll i=0; i<m; i++){
        ll u, v, w;
        cin>>u>>v>>w;
        graph1[u].push_back({v, w});
        graph2[v].push_back({u, w});
    }

    dijkstra1(s);
    dijkstra2(d);
    ll ans=-1;
    for(ll u=1; u<=n; u++){
        for(auto &e: graph1[u]){
            
            ll cost=dist1[u]+e.second+dist2[e.first];
            if(cost<=p)ans=max(ans, e.second);
            // cout<<cost<<" "<<mi<<" "<<midist1[u]<<" "<<midist2[e.first]<<endl;
        }
    }
    cout<<ans<<endl;
}
int main(){
    fastio;
    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++)solve(i);
}