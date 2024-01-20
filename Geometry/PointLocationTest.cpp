/*
    if p1(x1, y1) is more left to p2(x2, y2) then slop of p1> slop of p2
    x1/y1>x2/y2 -->x1y2-x2y1<0
*/
//cses
#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct point{
    ll x,y;
    void read(){
        cin>>x>>y;
    }
    point operator -(const point&other)const{//const means i can,t change anything.
        return {x-other.x, y-other.y};
    }
    void operator -=(const point&other){
        x-=other.x;
        y-=other.y;
    }
    ll operator *(const point &other)const{
        return  x*other.y - other.x*y;
    }
};
void solve()
{
    point p1, p2, p3;
    p1.read(), p2.read(), p3.read();
    p2=p2-p1;
    p3=p3-p1;
    ll cross=p3*p2;
    if(cross<0)cout<<"LEFT\n";
    else if(cross>0)cout<<"RIGHT\n";
    else cout<<"TOUCH\n";
}
int main()
{
    ll t;
    cin>>t;
    while(t--)solve();
}