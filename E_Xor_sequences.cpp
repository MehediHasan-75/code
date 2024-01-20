#include<bits/stdc++.h>
using  namespace std;
#define ll long long
#define mod 1000000007
vector<vector<ll> > multiply(vector<vector<ll> > &a, vector<vector<ll> > &b) {
    vector<vector<ll> > ans(a.size(), vector<ll>(b[0].size(), 0));
    for(ll i=0;i<a.size();i++){
        for(ll j=0;j<b[0].size();j++){
            for(ll k=0;k<b.size();k++){
                ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%mod;
            }
        }
    }
    return ans;
}
vector<vector<ll> > power(vector<vector<ll> >&a, ll k){
    ll n=a.size();
    vector<vector<ll>>ans(n,vector<ll>(n,0));
    if(k==0){
        for(ll i=0; i<n; i++)ans[i][i]=1;
        return ans;
    }
    ans=power(a, k/2);
    ans=multiply(ans, ans);
    if(k%2)ans=multiply(ans, a);
    return ans;
}
int main(){
    ll n, k;
    cin>>n>>k;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    vector<vector<ll>>adj(n, vector<ll>(n, 0));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            if((__builtin_popcountll((v[i]^v[j])))%3==0)adj[i][j]=1;
        }
    }
    vector<vector<ll>>ans=power(adj , k -1);
    ll sum=0;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            // cout<<ans[i][j]<<" ";
            sum=(sum+ans[i][j])%mod;
        }
        // cout<<endl;
    }
    cout<<sum<<endl;
    return 0;
}