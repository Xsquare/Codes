
#include <bits/stdc++.h>
#define lli long long
#define M 1000000007

using namespace std;

lli n;
lli A[32][32], B[32][32];
lli res[32][32];
lli ans[32][32];

void add_1(lli A1[][32])
{
    for ( int i = 1; i <= n; i++ ) {
        A1[i][i]++;
        if ( A1[i][i] >= M ) A1[i][i] -= M;
    }
    return;
}

void add(lli A1[][32], lli A2[][32])
{
    lli C[32][32];
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= n; j++ ) {
            C[i][j] = (A1[i][j] + A2[i][j])%M;
        }
    }
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= n; j++ ) {
            A1[i][j] = C[i][j];
        }
    }
    return;
}

void mul(lli A1[][32], lli A2[][32])
{
    lli C[32][32];
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= n; j++ ) {
            C[i][j] = 0;
            for ( int k = 1; k <= n; k++ ) {
                C[i][j] = (C[i][j] + (A1[i][k]*A2[k][j])%M);
                if ( C[i][j] >= M ) C[i][j] -= M;
            }
        }
    }

    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= n; j++ ) A1[i][j] = C[i][j];
    }
    return;
}

void fast_pow(lli x)
{
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= n; j++ ) {
            if ( i == j ) res[i][j] = 1;
            else res[i][j] = 0;
            B[i][j] = A[i][j];
        }
    }
    while ( x > 0 ) {
        if ( x&1 ) mul(res,B);
        mul(B,B);
        x >>= 1;
    }
}


void f(lli x){
    if ( x == 1 ) {
        fast_pow(1);
        for ( int i = 1; i <= n; i++ )  {
            for ( int j = 1; j <= n; j++ ) ans[i][j] = res[i][j];
        }
        return;
    }
    if ( x&1 ) {
        f(x-1);
        fast_pow(x);
        add(ans,res);
    }
    else {
        f(x/2);
        fast_pow(x/2);
        add_1(res);
        mul(ans,res);
    }
}

int main()
{
    lli m,k,x,y,q;
    cin >> n >> m >> k;
    while ( m-- ) {
        cin >> x >> y;
        A[x][y]++;
    }
    f(k);
    //queries for answering ways from node a to node b of length atmost K
    cin >> q;
    while ( q-- ) {
        cin >> x >> y;
        cout << ans[x][y] << endl;
    }
    return 0;
}
