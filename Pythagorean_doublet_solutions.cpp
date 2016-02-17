#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <utility>
#define MOD 1000000007
typedef long long LLD;
using namespace std;
int main()
{
    int t, d;
    cin >> t;
    while(t--)
    {
        	cin >> d;
        	LLD ans = 1, p;
        	for(int i = 2; i*i <= d; i ++)
        	{
        	    p = 0;
        	    while(d % i == 0)
        	    {
        		           d /= i;
        		           p++;
        	    }
        	    if(i % 4 == 1) ans *= (2*p+1);
        	}
        	if(d != 1 && d % 4 == 1) ans *= 3;
        	cout << 4*ans << endl;
    }
    return 0;
}
