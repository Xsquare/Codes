#include <iostream>
using namespace std;
void extended(int a, int b, int& gcd, int& x, int& y)
{
        x=0, y=1; 
        int u=1, v=0, m, n, q, r;
        gcd = b;
        while (a!=0) {
                q=gcd/a; r=gcd%a;
                m=x-u*q; n=y-v*q;
                gcd=a; a=r; x=u; y=v; u=m; v=n;
        }
}
int main() {
  int gcd, x, y, a, m; 
  cin>>a>>m;
  extended(a, m, gcd, x, y);
  if(x<0) x=x+m;
  y-=a;
  cout << x << " " << y << " " << gcd << endl;
  extended(168, 352, gcd, x, y);
  cout << x << " " << y << " " << gcd << endl;
  extended(3458, 4864, gcd, x, y);
  cout << x << " " << y << " " << gcd << endl;
  system("pause");
  return 0;
}
