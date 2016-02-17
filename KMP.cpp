#include <bits/stdc++.h>
#define MAX 1000005

using namespace std;

string s;
int n;
int lps[MAX];

void pre()
{
    lps[0] = 0;
    int len = 0;

    for ( int i = 1; i < n; i++ ) {
        while ( len > 0 && s[i] != s[len] ) len = lps[len-1];
        len += (s[i] == s[len]);
        lps[i] = len;
    }
    return;
}

int main()
{
    cin >> s;
    n = (int)s.size();
    pre();
    return 0;
}
