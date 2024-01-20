#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> factors;
void primefactor(ll n)
{
    for (ll i = 2; ; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
                factors.push_back(i);
            }
        }
    }
    if (n > 1)
        factors.push_back(n);
}
int main(){
    int n;

    primefactor(n);
    for(auto &it1: factors)cout<<it1<<" ";
}