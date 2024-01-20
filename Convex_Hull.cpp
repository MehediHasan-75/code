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
    bool operator <(const point &other)const{
        return make_pair(x, y)<make_pair(other.x, other.y);
    }
    ll cross_res(const point &p2, const point &p3)const{
        return (p2-*this)*(p3-*this);
    }
};
int main(){
    ll n;
    cin>>n;
    vector<point>v(n);
    for(auto &it: v)it.read();
    sort(v.begin(), v.end());//sort from left to right
    //for(auto &it: v)cout<<it.x<<" "<<it.y<<endl;
    vector<point>ans;
    for(int rep=0; rep<2; rep++){
        int s=ans.size();
        for(auto c: v){
            while(ans.size()>=s+2){
                point a=ans.end()[-2], b=ans.end()[-1];
                if(a.cross_res(b,c)<=0)break;//b on the left from c or collinear wrt a
                ans.pop_back();//if not remove it
            }
            ans.push_back(c);
        }
        ans.pop_back();//remove rightmost point in each iteration.(for avoiding overlapping)
        reverse(v.begin(), v.end());
    }
    cout<<ans.size()<<endl;
    for(auto &it: ans)cout<<it.x<<" "<<it.y<<endl;
}