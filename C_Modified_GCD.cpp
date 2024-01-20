#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a, b;
    cin>>a>>b;

    vector<ll>divi;
    for(ll i=1; i*i<=a; i++){
        if(a%i==0){
            ll x=a/i, y=i;
            if(b%x==0){
                divi.push_back(x);
            }
            if(x==y)continue;
            if(b%y==0){
                divi.push_back(y);
            }
        }
    }
    sort(divi.begin(), divi.end());
    ll q;
    cin>>q;
    while(q--){
        ll a, b;
        cin>>a>>b;
        if(a>b)swap(a, b);

        ll lo=0, hi=divi.size()-1, starta=-1, startb=-1;
        
        while(hi>=lo){
            ll mid=(hi+lo)>>1;

            if(divi[mid]>=a){
                starta=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }

        lo=0, hi=divi.size()-1;
        while(hi>=lo){
            ll mid=(hi+lo)>>1;

            if(divi[mid]<=b){
                startb=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        if(startb!=-1 and divi[startb]>=a){
            cout<<divi[startb]<<endl;
        }
        else if(starta!=-1 and divi[starta]<=b){
            cout<<divi[starta]<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}