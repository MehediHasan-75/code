#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
vector<ll>graph[N], a(N), b(N), in(N, 0), posans, negans;
ll n, sum=0;

void tropo(){
    queue<ll>qu;
    for(ll i=1; i<=n; i++){
        if(in[i]==0)qu.push(i);
    }

    while(qu.size()){
        ll nd=qu.front(), taken=0;
        qu.pop();
        if(a[nd]>=0){
            taken=1;
            sum+=a[nd];
            posans.push_back(nd);
        }
        else negans.push_back(nd);
        for(auto &it: graph[nd]){
            if(taken){
                a[it]+=a[nd];
            }
            in[it]--;
            if(in[it]==0)qu.push(it);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>n;

    for(ll i=1; i<=n; i++)cin>>a[i];

    for(ll i=1; i<=n; i++){
        cin>>b[i];
        if(b[i]==-1)continue;
        graph[i].push_back(b[i]);// i will come before b[i] if positive.
        in[b[i]]++;
    }
    tropo();
    for(ll i=0; i<negans.size(); i++){
        sum+=a[negans[i]];
    }
    cout<<sum<<endl;
    for(auto &it: posans)cout<<it<<" ";
    reverse(negans.begin(), negans.end());
    for(auto &it: negans)cout<<it<<" ";
}