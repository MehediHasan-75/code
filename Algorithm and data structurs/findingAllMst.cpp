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