//fast power
lli fast_pow(lli a, lli b)
{
    lli ans = 1;
    while(b > 0){
        if(b & 1){
            ans = (ans * a) % M;
        }
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}

//if m is prime, ETF of m is m - 1
//Generally, formula is fast_pow(a, ETF(m) - 1)
//For this to be valid, gcd(a,m) should be 1 i.e they should be co-prime to each other.
lli modInverse(lli a, lli m) {
    return fast_pow(a, m - 2);
}

//precomputes factorial modulo M and inverse Facctorial modulo M
void pre_fact() {
    invFact[0] = 1;
    fact[0] = 1;
    for ( lli i = 1; i <= LIM; i++ ) {
        fact[i] = (fact[i-1]*i)%M;
        invFact[i] = (invFact[i-1]*modInverse(i,M)) % M;
    }
    return;
}

lli cal_ncr(lli n, lli k) {
    if ( n == 0 && k == 0 ) return 1;
    if ( n == 0 ) return 0;
    if ( k == 0 ) return 1;
    lli ans = fact[n];
    ans = (ans*invFact[k])%M;
    ans = (ans*invFact[n - k])%M;
    return ans;
}

//C(n , r) = C(n - 1, r - 1) + C( n - 1, r )
void pre_ncr()
{
    C[0][0] = 1;
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 0; j <= i; j++ ) {
            if ( j == 0 || i == j ) C[j][j] = 1;
            else {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j])
                if ( C[i][j] >= M  ) C[i][j] -= M;
            }
        }
    }
    return;
}
