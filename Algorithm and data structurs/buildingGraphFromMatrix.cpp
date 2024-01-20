vector<ll>graph[25], val(25, 0);// 25=maximum number of nodes
vector<pair<ll,ll>>moves={{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
bool valid(ll x, ll y, ll row, ll col){
    return x<row and y<row and x>=0 and y>=0;
}
void build_graph(string s[], ll row, ll col){
    for(ll i=0; i<row; i++){
        for(ll j=0; j<col; j++){
            ll node= i*row + j;// representing each cell as a node of a graph.
            if(s[i][j]=='J'){//meet our necessery condition then set the value of node
                val[node]=1;
            }
            for(auto &[x, y]:moves){
                ll new_i=i+x, new_j=j+y;

                if(valid(new_i, new_j, row, col)){//means cell is adjacent to node's cell
                    ll new_node=new_i*row+new_j;
                    graph[node].push_back(new_node);
                }
            }
        }
    }
}