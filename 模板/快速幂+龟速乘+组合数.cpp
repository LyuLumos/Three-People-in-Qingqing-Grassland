// 快速幂板子
ll qpow(ll a,ll b,ll mod){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod; a=a*a%mod;} ans=(ans%mod+mod)%mod;return ans;}
//龟速乘板子
ll mul(ll a,ll b,ll mod){ll ans = 0;a%=mod,b%=mod;for(;b;b>>=1){if(b&1) ans+=a;if(ans>=mod)ans-=mod;a<<=1;if(a>=mod)a-=mod;} return ans;}

//组合数板子
ll jc[200020],jcinv[200020];
ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod; a=a*a%mod;} return ans;}
ll inv(ll a){return qpow(a,mod-2);}
void init(int n){jc[1]=1;jcinv[1]=inv(1);for(int i=2;i<=n;++i){jc[i]=jc[i-1]*i%mod;jcinv[i]=inv(jc[i]);}}
ll C(int n,int m){if(n<m || n<0 ||m<0)return 0; if(m==0 || m==n) return 1;return jc[n]*jcinv[m]%mod*jcinv[n-m]%mod;}
