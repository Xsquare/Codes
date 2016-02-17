#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define lim 10000000

using namespace std;

static int p[10000002];
static int mu[10000002];

void pre()
{
     long long i,j,t=(int)(sqrt(lim));
     
     for ( i = 1; i <= lim; i++ ) mu[i] = 3;
     for ( i = 2; i <= t; i++ ) {
         if ( mu[i] == 3 ) {
            for ( j = i*i; j <= lim; j += i*i ) {     
                mu[j] = 2;
            }
         }
     }
     
     memset(p, 0, sizeof(p));
     
     for ( i = 2; i <= lim; i++ ) {
         if ( !p[i] ) {
              mu[i] = -1;
              for ( j = 2*i; j <= lim; j += i ) {
                  p[j] = 1;
                  if ( mu[j] == 2 ) mu[j] = 0;
                  else if ( mu[j] == 3 ) mu[j] = -1;
                  else if ( mu[j] == -1 ) mu[j] = 1;
                  else if ( mu[j] == 1 ) mu[j] = -1;
              }
         }
     }
     mu[1] = 1;
     return;
}

