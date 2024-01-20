#include<bits/stdc++.h>
#define ll long long
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
ll mod = 1000000007;
vector<ll>power_p(100);
void precal(){
    power_p[0]=1;
    for(ll i=1; i<85; i++){
        power_p[i]=(power_p[i-1]*131)%mod;
    }
}
ll pwr(ll a,ll b)
{
    if(b==0) return 1;
    ll ret=pwr(a,b/2)%mod;
    if(b%2==0) 
    {
        return ((ret)*(ret))%mod;
    }
    else return ((a%mod)*(((ret)*(ret))%mod))%mod;
    
}
ll inverseMod(ll a){
   return pwr(a, mod-2);
}
void solve(ll tc){
    string s;
    cin>>s;
    ll hash=0, hash_size=s.length();
    vector<ll>h(s.size()+1);
    for(ll i=0; i<s.size(); i++){
        hash=(hash+(power_p[i]*(s[i]-'\0'))%mod)%mod;
        h[i+1]=hash;
    }
    //for(ll i=1; i<=hash_size; i++)cout<<h[i]<<" ";
    //hash left=h[hahs_size-i], hash right=(h[hash_size]-h[i])*Inverse_mod(131,i)
    for(ll i=1; i<=hash_size; i++){
        //cout<<h[hash_size-i]<<" "<<(((h[hash_size]-h[i])*inverseMod(power_p[i]))%mod)<<" "<<i<<endl;
        if(s.size()%i==0 and h[hash_size-i]==(((h[hash_size]-h[i])*inverseMod(power_p[i]))%mod)){
            cout<<i<<'\n';
            break;
        }
    }
    if(tc)cout<<'\n';
    
}
int main(){
    fastio;
    ll t;
    cin>>t;
    precal();
    // for(ll i=0; i<3; i++)cout<<power_p[i]<<"  ";
    while(t--){
        solve(t);
    }
}