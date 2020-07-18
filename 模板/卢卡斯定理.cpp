ll jc[200020],jcinv[200020];
ll qpow(ll a,ll b,int mod){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod; a=a*a%mod;} return ans;}
ll inv(ll a,int mod){return qpow(a,mod-2,mod);}
void init(int n,int mod){jc[1]=1;jcinv[1]=inv(1,mod);for(int i=2;i<=n;++i){jc[i]=jc[i-1]*i%mod;jcinv[i]=inv(jc[i],mod);}}
ll C(int n,int m,int mod){if(m==0 || m==n) return 1;return jc[n]*jcinv[m]%mod*jcinv[n-m]%mod;}
ll Lucas(ll n,ll m,ll p)
{
    if(n<m || n<0 ||m<0) return 0;
    if(m==0) return 1;
    return Lucas(n/p,m/p,p)*C(n%p,m%p,p)%p;
}
