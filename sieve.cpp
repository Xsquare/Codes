//calculates prime factors upto LIM
void cal_prime()
{
    for ( int i = 2; i <= LIM; i++ ) {
        primes.push_back(i);
        for ( int j = 2*i ; j <= LIM; j += i ) vis[j] = true;
    }
    vis[1] = true;
    return;
}

//calculates ETF (number of integers <= X and coprime to X) for each X upto LIM
void cal_etf()
{
    ETF[1] = 1;
    for ( int i = 2; i <= LIM; i++ ) {
        if ( !ETF[i] ) ETF[i] = i - 1;
        for ( int j = 2*i; j <= LIM; j++ ) {
            if ( !ETF[j] ) ETF[j] = j;
            else ETF[j] = ETF[j]/i * (i - 1);
        }
    }
    return;
}

//calculates divisors of all numbers upto LIM (slow)
void cal_div()
{
    for ( int i = 1; i <= LIM; i++ ) {
        for ( int j = i; j <= LIM; j += i ) divisors[j].push_back(i);
    }
    return;
}

//calculates divisors of all numbers upto LIM (fast)
void cal_div()
{
    int SQRT_LIM = (int)sqrt(LIM);
    for ( int i = 1; i <= SQRT_LIM; i++ ) {
        for ( int j = i; j <= LIM; j += i ) {
            divisors[j].push_back(i);
            if ( j/i > SQRT_LIM && j/i != i ) divisors[j].push_back(j/i);
        }
    }
    return;
}

