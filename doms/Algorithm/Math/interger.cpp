#define ll long long 


// lucas C(n,m)%prime
int C(ll n,ll m,int mod)
{
    if(m==0)return 1;
    return C(n/mod,m/mod,mod)*C(n%mod,m%mod,mod)%mod;
}


