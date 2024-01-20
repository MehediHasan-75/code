#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ll n;
    cin>>n;
    vector<ll>sequence;

    for(ll i=0; i<n; i++){
        ll value;
        cin>>value;

        ll ind=lower_bound(sequence.begin(), sequence.end(), value)-sequence.begin();
        //here we will get the position where the value appare or the value greater than this.
        //if found greater value in ind. this will contribute same. so we should keep smaller value.
        //if every numer is less than this. so we can easily take this number also to increasing length.

        if(ind==sequence.size()) sequence.push_back(value);
        else sequence[ind]=value;
    }
    cout<<sequence.size();
}   