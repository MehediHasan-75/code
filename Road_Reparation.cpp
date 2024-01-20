bool vis[N];
ll parnt[N], level[N];
void bfs(ll source)
{
    queue<ll>qu;
    qu.push(source);
    parnt[source]=-1;
    level[source]=0;
    vis[source]=1;
    while(!qu.empty())
    {
        ll parent=qu.front();
        qu.pop();
        for(auto &child: graph[parent])
        {
            if(vis[child])continue;
            qu.push(child);
            vis[child]=1;
            level[child]=level[parent]+1;
            parnt[child]=parent;
        }
    }
}