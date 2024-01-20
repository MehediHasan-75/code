#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5;
bool board[N][N];
bool valid(ll row, ll col){
    //up
    ll r=row-1, c=col;
    while(r>=0){
        if(board[r][c])return false;
        r--;
    }
    //up right
    r=row-1, c=col+1;
    while(c<N and r>=0){
        if(board[r][c])return false;
        c++, r--;
    }
    //up left
    r=row-1, c=col-1;
    while(c>=0 and r>=0){
        if(board[r][c])return false;
        c--, r--;
    }
    return true;
}
void display(){
    for(ll i=0; i<N; i++){
        for(ll j=0; j<N;j++){
            if(board[i][j])cout<<'Q';
            else cout<<"X";
        }
        cout<<endl;
    }
    cout<<endl;
}
ll Queen(ll row){
    if(row==N){
        display();
        return 1;
    }
    ll cnt=0;
    for(ll col=0; col<N; col++){
        if(valid(row, col)){
            board[row][col]=true;
            cnt+=Queen(row+1);
            board[row][col]=false;
        }
    }
    return cnt;
}
int main(){
    memset(board, false, sizeof(board));
    cout<<Queen(0)<<endl;;
}