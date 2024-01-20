#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define prnt(x) for(auto &it: x)cout<<it<<" ";cout<<"\n";
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

typedef long long ll;
typedef vector<ll> vll;
const ll N = 2e5 + 10, inf=2e18;
ll mod = 1000000007;
void solve(ll tc)
{
    ll row, col;
    cin>>row>>col;
    ll mx_r=0, mx_c=0, cnt_r=0, cnt_c=0, r=-1, c=-1;
    char s[row][col];
    for(ll i=0; i<row; i++){
        cnt_c=0;
        for(ll j=0; j<col; j++){
            cin>>s[i][j];
            if(s[i][j]=='#'){
                cnt_c++;
                if(r==-1 and c==-1)r=i, c=j;
            }
        }
        if(cnt_c)cnt_r++;
        mx_r=max(cnt_r, mx_r);
        mx_c=max(cnt_c, mx_c);
    }
    for(ll i=0; i<row; i++){
        for(ll j=0; j<col; j++){
            if(s[i][j]=='.'){
                ll cnt=0;
                if(i-1>=0 and s[i-1][j]=='#')cnt++;
                if(j-1>=0 and s[i][j-1]=='#')cnt++;
                if(i+1<row and s[i+1][j]=='#')cnt++;
                if(j+1<col and s[i][j+1]=='#')cnt++;

                if(cnt>1){
                    cout<<i+1<<" "<<j+1<<endl;
                    return;
                }
            }
        }
    }
    
}
int main()
{
    fastio;ll T = 1;
    //cin >> T;
    for (ll i = 1; i <= T; i++)solve(i);
    return 0;
}

