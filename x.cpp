vector<ll> primes;vector<ll> mark(N,0);
vector<ll> lp(N,0), hp(N,0);
void siv()
{
    mark[0]=mark[1]=1;
    for(ll i=2; i<=N; i++)
    {
        if(!mark[i])
        {
            lp[i]=hp[i]=i;
            for(ll j=2*i; j<=N; j+=i)
            {
                mark[j]=1;
                hp[j]=i;
                if(!lp[j])lp[j]=i;
            }
        }
    }
}
vector<ll> prime_factors;
void pr_fact(ll n)
{
    while(n>1)
    {
        ll prime_div=lp[n];// we can also use hp[n]
        while(n%prime_div==0)
        {
            n/=prime_div;
            prime_factors.push_back(prime_div);
        }
    }
}