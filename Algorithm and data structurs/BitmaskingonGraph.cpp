map<ll,ll>mp;

ll func(ll mask, ll jersey){
    // cout<<jersey<<" ";
    ll total=__builtin_popcountll(mask);
    if(total==7){
        if(jersey>3){
            if(mp[mask]==0){
                mp[mask]=1;
                return 1;
            }
            return 0;
        }

        return 0;
    }
    ll ans=0;
    for(ll u=0; u<25; u++){//25 = maximum number of nodes
        if(mask&(1ll<<u)){
            for(auto v: graph[u]){
                if(mask&(1ll<<v))continue;
                ans+=func(mask|(1ll<<v), jersey+val[v]);
            }
        }
    }
    return ans;
}