#include<bits/stdc++.h>
using namespace std;
const int LOG=21, N=3e5+10;
#define ll long long
#define endl "\n"
vector<ll>v(N);
ll stablegc[LOG][N], n;

ll get_ans(ll l, ll r){
    ll len = r - l + 1, i = log2(len);
    // cout<<i<<endl;
    return __gcd(stablegc[i][l], stablegc[i][r - (1 << i) + 1]);   
}
void spharseTable(vector<ll> &array)
{
    copy(array.begin(), array.end(), stablegc[0]);
    for (ll i = 1; i < LOG; i++)
    {
        for (ll j = 0; j + (1ll << i) < N; j++)
        {
            stablegc[i][j]=__gcd(stablegc[i-1][j], stablegc[i-1][j + (1 << (i - 1))]);
        }
    }
}
ll get_left(ll ind){
    ll l=0,r=ind,ans=0,mid;
    while(l<=r){
        mid=(r+l)/2;
        if(get_ans(mid,ind)==v[ind]){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}

ll get_right(ll ind){
    ll l=ind,r=n-1,ans=0,mid;
    while(l<=r){
        mid=(r+l)/2;
        if(get_ans(ind,mid)==v[ind]){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}

int main(){
    cin>>n;
    for(ll i=0; i<n; i++)cin>>v[i];

    spharseTable(v);
    ll mx=0, len[n]={0}, left[n]={0};
    for(ll i=0;i<n;i++){
        ll l = get_left(i), r=get_right(i);
        len[i] = r-l;
        left[i]=l;
        mx = max(mx,len[i]);
    }
    // cout<<mx<<endl;
    set<ll>st;

    for(ll i=0; i<n; i++){
        if(len[i]==mx){
            st.insert(left[i]);
        }
    }
    cout<<st.size()<<" "<<mx<<endl;
    for(auto &it: st)cout<<it+1<<" ";
    cout<<endl;
}