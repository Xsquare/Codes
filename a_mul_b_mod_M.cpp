unsigned long long mulmod(unsigned long long a, unsigned long long b, unsigned long long m )
{
    if(a>m)
        a=a%m;
    if(b>m)
        b=b%m;
    unsigned long long ret = 0;
    if(a<b)
        swap(a,b);
    while(b)
    {
        while(a<m)
        {
            if(b&1)
                ret += a;
            a<<=1;
            b>>=1;
        }
        a-=m;
        while(ret>=m)
            ret-=m;
        if(a<b)
            swap(a,b);
    }
    return ret;
}
