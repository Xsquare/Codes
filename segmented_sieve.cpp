#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

#define lli long long int
#define MAX 1000000 // sqrt of maximum constraint
#define LMT 1000 // sqrt of MAX

bool A[1000005];
bool seg[1000005];
lli P[1000005];
lli p = 0;

void sieve()
{
    for(int i=3;i<=LMT;i+=2)
    {
        if(!A[(i-3)>>1])
        {
            for(int j=i*i;j<=MAX;j+=2*i)
                A[(j-3)>>1]=1;
        }
    }
    P[p++] = 2;
    for(int i=0;i<=MAX/2;i++) {
        if(!A[i]) P[p++]=2*i+3;
    }
    return;
}

lli segmented_sieve(lli a, lli b)
{
         memset(seg,0,sizeof(seg));
         for(lli i=0;i<p && P[i]*P[i]<=b;i++)
         {
             lli tmp=a/P[i];
             tmp=tmp*P[i];
            for(lli in=tmp;in<=b;in+=P[i])
            {
                if(in-a<0) continue;
                if(P[i]==in) continue;
                lli in1=in-a;
                seg[in1]=1;
            }
        }
        lli c=0;
        for(lli i=0;i<=b-a;i++)
        {
            if(seg[i]==0) c++;
        }
        if ( 1 >= a && 1 <= b ) c--;
        return c;
}

int main()
{
    sieve();
    int t;
    lli a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        long long ans = segmented_sieve(a,b);
        cout << ans << endl;
    }
    return 0;
}
