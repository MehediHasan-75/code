/*There are two line segments: the first goes through the points (x1,y1) and (x2,y2),and the second goes through the points (x3,y3) and (x4,y4).
Your task is to determine if the line segments intersect, i.e., they have at least one common point.*/
/*
    -->check if p3 and p4 is completly left or right of point p1, p2
    -->check vice versa
    -->
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    ll cross_res(const point &p2, const point &p3)const{
        return (p2-*this)*(p3-*this);
    }
    ll on_seg(const point&p2, const point&p3)const{
        return ((min(p2.x, p3.x)<=x and x<=(max(p2.x, p3.x))) and (min(p2.y, p3.y)<=y and y<=(max(p2.y, p3.y))));
    }
};
bool intersect(point p1, point p2, point p3, point p4)
{
  ll d1=p1.cross_res(p3, p4), d2=p2.cross_res(p3, p4), d3=p3.cross_res(p1, p2), d4=p4.cross_res(p1, p2);
  //cout<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<endl;
  if(((d1>0 and d2<0) or (d1<0 and d2>0)) and ((d3>0 and d4<0) or (d3<0 and d4>0)) )return true;
  else if(d1==0 and p1.on_seg(p3, p4))return true;
  else if(d2==0 and p2.on_seg(p3, p4))return true;
  else if(d3==0 and p3.on_seg(p1, p2))return true;
  else if(d4==0 and p4.on_seg(p1, p2))return true;
  else return false;

}
int main()
{
    ll n, m;
    cin>>n>>m;
    vector<point>v(n);
    for(auto &it: v)it.read();
    for(int i=0; i<m; i++){
        ll cnt=0;
        point p1;
        p1.read();
        point p2={p1.x+1, INT_MAX};
        bool boundary=false;
        for(int j=0; j<n; j++){
            if(p1.on_seg( v[j], v[j==n-1?0:j+1]) and p1.cross_res(v[j], v[j==n-1?0:j+1])==0){
                boundary=true;
                break;
            }
            if(intersect(p1, p2, v[j], v[j==n-1?0:j+1]))cnt++;
        }
        if(boundary)cout<<"BOUNDARY\n";
        else if(cnt%2==0)cout<<"OUTSIDE\n";
        else cout<<"INSIDE\n";
    }
}

