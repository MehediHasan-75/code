#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
    ll n, sum=0;
    cin>>n;

    map<ll,ll>prefix, suffix;

    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
        sum+=v[i];
        suffix[v[i]]++;
    }

    if(sum%2){
        cout << "NO\n";
        return 0;
    }
    ll pre_sum=0;

    for(ll i=0; i<n; i++){
        pre_sum+=v[i];
        suffix[v[i]]--;
        prefix[v[i]]++;
        ll need=sum/2-pre_sum;
        // case 1-->equally divided
        //case 2--->suffix has extra sum so search needed element in suffix.
        //case 3--->prefix has extra sum so search in prefix so that we can remove it from prefix and move to suffix.
        if(need==0 or (need>0 and suffix[need]) or (need<0 and prefix[-need])){
            // cout<<need<<" "<<pre_sum<<" "<<i<<endl;
            cout << "YES\n";
            return 0;
        }      

    }
    cout << "NO\n";
}