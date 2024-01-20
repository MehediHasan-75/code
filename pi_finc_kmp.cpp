#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>func(string p){
    ll n=p.size();
    vector<ll>pi(n, 0);
    for(ll i=1; i<n; i++){
        ll j=pi[i-1];//previous kototuku matched(from begining)
        while(j>0 and p[j]!=p[i]){
            j=pi[j-1];
        }
        if(p[j]==p[i]){
            j++;
        }//match korar por theke(actually p[j+1] ekhane 0 base er jonno p[j]) porer 1 character match korle match e value(pi) 1 barbe.
        pi[i]=j;
    }
    return pi;
}
int main(){
    string p;
    cin>>p;
    vector<ll>pi=func(p);
    for(auto &it: pi)cout<<it<<endl;
}