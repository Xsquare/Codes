LL findPeriod(int M) {
    int a = 1, b = 1, c = -1;
    LL p = 0, cnt = 3;
    if (M <= 20) {
        while (1) {
            c = (a + b);
            if (c >= M) c -= M;
            if (c == 1 && b == 1) {
                cnt -= 2;
                break;
            }
            a = b;
            b = c;
            cnt++;
        }
    } else {
        int ret = M % 5;
        if (ret == 1 || ret == 4) cnt = M - 1;
        else cnt = (M * (LL)M - 1);
    }
    return cnt;
}

LL findPisano(int M) {
    LL period = -1;
    for (int i = 2; i * i <= M; i++) {
        int cp = 1;
        if (M % i == 0) {
            while (M % i == 0) {
                cp *= i;
                M /= i;
            }
            if (period == -1) period = findPeriod(i) * (cp/i);
            else period = LCM(period, findPeriod(i) * (cp/i));
        }
    }
    if (M > 1) {
        if (period == -1) period = findPeriod(M);
        else period = LCM(period, findPeriod(M));
    }
    //if (period > 1e15) cerr<<"WATCH OUT\n";
    return period;
}
