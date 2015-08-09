// If number can be expressed as a sum of two squares.
#include <bits/stdc++.h>
using namespace std;
int func(long long n)
{
          long long t,i,flag = 0,p;
          if ( n%2 == 0 ) {
                   p = 0;
                   while ( n%2 == 0  ) {
                           p++;
                           n = n/2;
                   }
          }
          t = int((sqrt)(n));
          for ( i = 3; i <= t; i += 2 ) {
                  if ( n%i == 0 ) {
                          p = 0;
                          while ( n%i == 0 ) {
                                  n = n/i;
                                  p++;
                          }
                          if ( i%4 == 3 ) {
                                   if ( p%2 != 0 ) return 0;
                          }
                  }
                  if ( n == 1 ) break;
          }
          if ( n != 1 ) {
                    if ( n%4 == 3 ) return 0;
          }
          return 1;
}

int main()
{
          int n;
          long long x;
          scanf("%lld", &n);
          while ( n-- ) {
                  scanf("%lld", &x);
                  if ( (prime(x) == 1 && x%4 == 1) || (x == 1) || (x == 2) || (x == 0) ) printf("YES\n");
                  else if ( func(x) == 0 ) printf("NO\n");
                  else printf("YES\n");
          }

          return 0;
}




