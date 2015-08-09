long long modpow(long long a,long long n){	// calc a^n (mod M)
	long long r=1;
	for(long long x=a;n;n>>=1,x=(x*x)%M) if(n&1) r=(r*x)%M;
	return r;
}
 
long long inv(long long a){	// find x s.t. a*x=1 (mod M) (M:prime)
	return modpow(a,M-2);
}
 
long long C(long long n,long long r){	// calc nCr (mod M) (M:prime)
	if(n<r)		return 0;
	if(n-r<r)	r=n-r;
 
	long long res=1;
	for(long long i=r;i>0;i--){
		res=(res*((n-i+1)%M))%M;
		res=(res*inv(i))%M;
	}
	return res;
}
