ll INF=1e18;
ll d[N][N];// adj matrix(if edge exist wt or 1 and if dosent infinity and s[i][i]=0
ll nxt[N][N];// initially next[i][j]=j;
void floyed_warshal()
{
    for (int k = 0; k < v; ++k) {
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                if (d[i][k] < INF && d[k][j] < INF)// safe from negative edges problem (reduce infinity though path dosent exist)
                    if(d[i][k] + d[k][j]<d[i][j])
                    {
                        d[i][j]=d[i][k] + d[k][j];
                        nxt[i][j]=nxt[i][k];//stores if we want to go node j form i what will be our next step.
                    }
            }
        }
}
vector<ll> path;
void find_path(ll i, ll j)
{
    path.push_back(i);
    while(i!=j)// while we won'n reach node j.
    {
        i=nxt[i][j];
        path.push_back(i);
    }
}
