#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k;
vector<pair<ll,ll>>v;
bool chk(ll d){
    // cout<<d<<endl;
    ll cnt=1, prev=v[0].first;
    for(ll i=1; i<v.size(); ){
        ll need=prev+d;
        // cout<<"need = "<<need<<" ";
        while(i<v.size() and v[i].first<need){
            i++;
        }
        if(i>=v.size())break;
        cnt++;
        //  cout<<"cnt = "<<cnt<<" ";
        // if(cnt>=n)return true;
        if(v[i].second==1)prev=need, i--;
        else prev=v[i].first;
        // cout<<"prev = "<<prev<<endl;
    }
    return cnt>=n;
}
int main(){
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    cin>>n>>k;
    // cout<<n<<" "<<k<<endl;
    for(ll i=0; i<k; i++){
        ll l, r;
        cin>>l>>r;
        v.push_back({l, 0});
        v.push_back({r, 1});
    }
    sort(v.begin(), v.end());
    // for(ll i=0; i<2*k; i++)cout<<v[i].first<<" "<<v[i].second<<endl;
    // for(ll i=1; i<10; i++)cout<<chk(i)<<" "<<i<<endl;
    ll ans=0, lo=0, hi=1e14+10;
    while(lo<=hi){
        ll mid=(hi-lo)/2+lo;
        if(chk(mid)){
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    cout<<ans<<endl;
}