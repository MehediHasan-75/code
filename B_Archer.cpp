#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
int main(){
    ld a, b, c, d;
    cin>>a>>b>>c>>d;
    cout<<fixed<<setprecision(6);
    ld ans=(a/b)/ (1- (1-a/b)*(1-c/d));
    cout<<ans<<endl;
}
/*
    Let, htf=hit in first chance, faif=failed both in first chance
    probability= htf+ faif*hts + fais* htt+----- =p*q^0+ p*q^1+p*q^2+---
               =p(q^0 +q^1+ q^2 +----)= p*(1-q)^-1;
    Here, p=a/b and q=failed first * failed second = (1-a/b) *(1- a/b) 
*/