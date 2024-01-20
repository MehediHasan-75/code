//Pick's theorem gives a way to find the area of polygons in a plane whose endpoints have integer vertices.
//(Area of the polygon P)=Inside(P)+(1/2)*​Boundary(P)−1.
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
int main(){
    ll n;
    cin>>n;
    vector<point>v(n);
    for(auto &it: v)it.read();
    ll area=0, boundary=0, in;
    for(int i=0; i<n; i++){
        point p1=v[i], p2=v[i+1==n? 0: i+1], diff=p1-p2;
        area+=(p1*p2);
        boundary+=__gcd(abs(diff.x), abs(diff.y));
    }
    in=(abs(area)-boundary+2)/2;
    cout<<in<<" "<<boundary<<endl; 
}