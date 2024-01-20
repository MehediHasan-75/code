#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n, k;
    cin>>n>>k;

    ll mx=(n*n +1)/2;

    if(mx<k)cout<<"NO\n";
    else{
        cout<<"YES\n";

        vector<vector<char>>ans(n, vector<char>(n, 'S'));

        for(ll i=0; i<n and k; i++){
            for(ll j=0; j<n and k; j++){
                if((i+j)%2==0){
                    k--;
                    ans[i][j]='L';
                }
            }
        }
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                cout<<ans[i][j];
            }
            cout<<endl;
        }
    }
    cout<<endl;
}