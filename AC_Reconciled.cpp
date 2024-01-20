bool flag=true;//if false not bicolorable
vector<ll>col(n, -1);
void dfs(int v, int c) {
    col[v] = c;// here color c=0 or 1
    for (auto to : graph[v]) {
        if (col[to] == -1) {
            dfs(to, c ^ 1);
        } else {
            if (col[to] == col[v]) {
               flag=false;
            }
        }
    }
}