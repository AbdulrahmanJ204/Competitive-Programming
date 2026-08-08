//iterative; O(log(n))
ll pow(ll x,ll n,ll mod){
    x%=mod;
    ll res=1;
    while(n){
        if(n%2){
            res=res*x%mod;
        }
        n/=2;
        x=x*x%mod;
    }
    return res;
}

//mod must be prime; O(log(mod))
ll inverse_mod(ll x,ll mod){
    x%=mod;
    return pow(x,mod-2,mod);
}


