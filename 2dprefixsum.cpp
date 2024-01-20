#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1002
ll matrix[M][M], r, c;
void input_matrix(){
    cin>>r>>c;
    for(ll i=0; i<r; i++){
        for(ll j=0; j<c; j++){
            cin>>matrix[i][j];
        }
    }
}
ll sum[M][M];
void precal(){
    for(ll i=1; i<=r; i++){
        for(ll j=1; j<=c; j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+matrix[i-1][j-1];
           cout<<sum[i][j]<<" ";
        }
        cout<<"\n";
    }
}
//x, y in one based index
ll getSum(ll x1, ll y1, ll x2, ll y2){
    return sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
}
int main(){
    input_matrix();
    precal();
    cout<<getSum(2, 2, 3, 3)<<endl;
}