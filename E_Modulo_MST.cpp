#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, k, u[100], v[100], w[100];

ll tree[10], mi=INT64_MAX;

int find(int a) {
    if (a == tree[a]) return a;
    return tree[a] = find(tree[a]);
}

void merge(int a, int b) {
    tree[find(a)] = find(b);
}

void func(ll ed, ll sm, ll mask){
    if(__builtin_popcount(mask)==n-1){
        iota(tree,tree+10, 0);
        for(ll i=0; i<m; i++){
            if(mask&(1<<i)){
                if(find(u[i])==find(v[i]))return;
                merge(u[i], v[i]);
            }
        }
        mi=min(mi, sm%k);
    }
    if(m==ed)return;
    func(ed+1, sm, mask);
    func(ed+1, sm+w[ed], mask|(1<<ed));
}
int main(){
    cin>>n>>m>>k;

    for(ll i=0; i<m; i++){
        cin>>u[i]>>v[i]>>w[i];
        u[i]--;
        v[i]--;
    }
    func(0, 0, 0);
    cout<<mi<<endl;
}

