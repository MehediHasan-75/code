#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
long long sum_all_divisors(long long n)
{
	long long sum = 0;
	for(ll i=1, j; i<=n; i=j){
        ll q=n/i;
        j=n/q+1;
        //cout<<i<<" "<<min(n,(j-1))<<endl;
        ll l=(i-1)%mod, r=min(n,(j-1))%mod;
        ll mi=(((l*(l+1))%mod)*500000004ll)%mod;
        ll pl=(((r*(r+1))%mod)*500000004ll)%mod;
        ll cnt=(pl-mi+mod)%mod;
        //cout<<cnt<<endl;
        sum=(sum+(cnt*q)%mod)%mod;
    }
    return sum;
}
int main()
{
	long long n;
    cin>>n;
	long long sum = sum_all_divisors(n);
	cout << sum << '\n';
	return 0;
}
