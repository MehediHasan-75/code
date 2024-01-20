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
    ll area=0;
    for(int i=0; i<n; i++){
        area+=(v[i]*v[i+1==n? 0: i+1]);
    }
    cout<<abs(area)<<endl;
}