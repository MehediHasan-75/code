#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1001;

vector<ll>factor[N];

void primefactor(ll n)
{
    ll num=n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            factor[num].push_back(i);
        }
    }
    if (n > 1)
        factor[num].push_back(n);
}

void solve(ll tc){
    cout<<"Case "<<tc<<": ";
    ll A, t;
    cin>>A>>t;
    if(A==t){
        cout<<0<<endl;
        return ;
    }
    bool vis[t+1];
    ll level[t+1];

    memset(vis, false, sizeof(vis));
    memset(level, 0, sizeof(level));

    vis[A]=1;
    level[A]=0;

    queue<ll>qu;
    qu.push(A);

    while(qu.size()){
        ll a=qu.front();
        qu.pop();

        for(auto &x: factor[a]){
            if(a+x<=t and !vis[a+x] and x!=A){
                qu.push(a+x);
                level[a+x]=level[a]+1;
                // cout<<a+x<<" "<<a<<" "<<level[a+x]<<" "<<level[a]<<endl;
                if(a+x==t){
                    cout<<level[t]<<endl;
                    return;
                }
                vis[a+x]=1;
            }
        }
    }
    cout<<-1<<endl;
}
int main(){
    for(ll i=1; i<=1000; i++)primefactor(i);
    // for(auto &it: factor[90])cout<<it<<" ";
    ll t;
    cin>>t;
    for(ll i=1; i<=t; i++)solve(i);
}