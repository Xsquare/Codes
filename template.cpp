// Author: Xsquare
#include <iostream>
#include <stack>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <sstream>

#define lli long long
#define M 1000000007

using namespace std;

//Code for FAST INPUT :)
template <typename T>
inline void fi(T *a)
{
    register char c=0;
    while (c<33) c=getchar_unlocked();
    *a=0;
    int tmp = 0;
    while (c>33)
    {
        if ( c == 45 ) tmp = 1;
        else *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
    if ( tmp == 1 ) *a = 0-(*a);
}

int main()
{

    return 0;
}
