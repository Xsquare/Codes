#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

long long func(long long a, long long b,long long n)
{
     long long i,t,sum,j,p1=0,p2=0,c;
     vector <long long> v;
     if ( n%2 == 0  ) {
        v.push_back(2);
        while ( n%2 == 0 ) n = n/2;
     }
     t = (long long)(sqrtl(n));
     for ( i = 3; i <= t; i += 2 ) {
         if ( n%i == 0 ) {
            v.push_back(i);
            while ( n%i == 0 ) n = n/i;
         }
         if ( n == 1 ) break;
     }
     if ( n != 1 ) v.push_back(n);
     
     t = (long long)(v.size());     
     
     for ( i = 0; i < 1 << t; i++ ) {
         sum = 1;
         c = 0;
         for ( j = 0; j < t; j++ ) {
              if ( i & (1<<j) ) {
                 c++;
                 sum *= v[j];
              }
         }
         if ( c&1 ) {
            p1 += a/sum;
            p2 += b/sum;
         }
         else {
              if ( sum != 1 ) {
                 p1 -= a/sum;
                 p2 -= b/sum;
              }
         }
     }
     p2 = b - p2;
     p1 = a - p1;
     return p2-p1;
}

int main()
{
    long long t,ans,a,b,c,i;
    
    scanf("%lld", &t);
    
    for ( i = 1; i <= t; i++ ) {
          scanf("%lld%lld%lld", &a, &b, &c);
          ans = func(a-1,b,c);
          printf("Case #%lld: %lld\n", i, ans);
    }
    
    return 0;
}

