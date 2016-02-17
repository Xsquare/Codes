// kth element in O(k)
void func(int n ,int k, int a[])
{
    int f,f1,b,b1,mid;
    f = 0;
    b = n-1;
    while ( f < b ) {
          f1 = f;
          b1 = b;
          mid = a[(f1+b1)/2];
          while ( f1 < b1 ) {
                if ( a[f1] >= mid ) {
                   swap(a[f1],a[b1]);
                   b1--;
                }
                else f1++;
          }
          if ( a[f1] > mid ) f1--;
          if ( k <= f1 ) b = f1;
          else f = f1+1;
    }
    printf("%d\n", a[k]);
    return;
}
