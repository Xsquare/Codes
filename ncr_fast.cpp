#include <iostream>
#define M 1000000007

using namespace std;

long long invModFact[105];

long long modpow(long long a, long long b) 
{
    long long ans = 1;
    while(b > 0){
        if(b & 1){
            ans = (ans * a) % M;
        }
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}
     
long long modInverse(long long a, long long m) {
    return modpow(a,m-2);
}

void pre() {
    invModFact[0] = 1;
    for ( long long i = 1; i < 105; i++ ) {
        invModFact[i] = (invModFact[i-1]*modInverse(i,M)) % M;
    }
    return;
}

long long func(long long n,long long k) {
    if ( n == 0 && k == 0 ) return 1;
    if ( n == 0 ) return 0;
    if ( k == 0 ) return 1;
    long long x = 1;
    for ( long long i = 0; i < k; ++i ) {
        x = (x*((n-i)%M)) % M;
    }
    return ((x*invModFact[k])%M);
}

int main()
{
    pre();
    cout << func(5,2) << endl;
    getchar();
    getchar();
    return 0;
}
