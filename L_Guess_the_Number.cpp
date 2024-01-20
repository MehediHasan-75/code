#include<bits/stdc++.h>
using namespace std;
int main(){
    typedef long long ll;
    ll lo=1, hi=1000000, ans=-1;
    while(hi>=lo){
        ll mid=(hi+lo+1)>>1;
        cout<<mid<<endl;
        string s;
        cin>>s;
        if(s=="<")hi=mid-1;
        else lo=mid+1, ans=mid;
    }
    cout<<"! "<<ans<<endl;
}