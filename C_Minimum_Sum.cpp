#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt[6][26];

int main(){
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    string s[n];

    for(ll i=0; i<n; i++){
        cin>>s[i];
        ll len=s[i].size();

        for(ll j=len-1; j>=0; j--){
            cnt[len-1-j][s[i][j]-'a']++;
            //cnt[pos][char]--> pos's are in increasing priority order.
        }
    }
    vector<pair<ll,ll>>v;
    //will store {value, char} if all the char is numbered as 1.
    for(ll i=0; i<26; i++){
        ll val=0, pwr=1;

        for(ll j=0; j<6; j++, pwr*=10){
            val+=pwr*cnt[j][i];
        }
        v.push_back({val, i});
    }
    sort(v.begin(), v.end(), greater<pair<ll,ll>>());
    //We have a chance to number a char as 0 and vanish it.
    // as we need to minimize the sum of all number
    // we sholud mark zero the number which has large unit contribution to all numbers and don't apperas as leading char.

    bool made_zero=0;
    ll ans=0, number_tag=1;
    for(ll i=0; i<26; i++){
        bool inLeadingPosition=0;
        ll val=v[i].first, ch=v[i].second;
        for(ll j=0; j<n; j++){
            if(s[j].front()-'a' == ch)inLeadingPosition=1;
        }

        if(!made_zero and !inLeadingPosition){
            made_zero=1;
            continue;
        }
        ans+=val*number_tag;
        number_tag++;
    }
    cout<<ans<<"\n";
}