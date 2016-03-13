void init()
{
    //Keep A[][] as a global transition matrix for each testcase.
    //Do something with A[][]
    //Initialize B[][] with A[][] and result[][] to indentity matrix
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            if ( i == j  ) res[i][j] = 1;
            else res[i][j] = 0;
            B[i][j] = A[i][j];
        }
    }
    return;
}

//multiplying two matrices A1[][] and A2[][] and storing the result in A[][]
void mul(lli A1[n][],lli A2[n][])
{
    lli A3[n][n];
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            A3[i][j] = 0;
            for ( int k = 0; k < n; k++ ) {
                A3[i][j] += (A1[i][k]*A2[k][j])%M;
                if ( A3[i][j] >= M ) A3[i][j] -= M;
            }
        }
    }
    for ( int i = 0; i < n; i++ ) {
         for ( int j = 0; j < n; j++ ) A1[i][j] = A3[i][j];
    }
    return;
}

//fast power
void func(lli x)
{
    while ( x > 0 ) {
        if ( x & 1 ) mul(res, B);
        mul(B, B);
        x >>= 1;
    }
    return;
}

