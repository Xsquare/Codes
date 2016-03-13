#include <bits/stdc++.h>
using namespace std;

#define lim 100000000

vector <bool> v(lim/2 + 100);

static int a[10000000];

bool chk(int x)
{
     if ( x == 2 ) return true;
     if ( x-3 < 0 ) return false;
     if ( (x-3)%2 == 0 ) {
          if ( v[(x-3)/2] ) return false;
          return true;
     }
     return false;
}

int main()
{
    int i,j,k=0,t = (int)(sqrt(lim));
    a[k++] = 2;
    for ( i = 3; i <= t; i += 2 ) {
        if ( !v[(i-3)/2] ) {
            for ( j = i*i; j < lim; j += 2*i ) {
                v[(j-3)/2] = 1;
            }
        }
    }

    for ( i = 0; i < lim/2; i++ ) {
        if ( !v[i] ) a[k++] = 2*i + 3;
    }

    for ( i = 0; i < 100; i++ ) cout << a[i] << endl;
    return 0;
}
