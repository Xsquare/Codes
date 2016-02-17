#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#define MAX 1000005

using namespace std;

string s,p;
int n;
int sz;

struct node {
    int fs;
    int sc;
    int idx;
    node() {  }
    node(int fs, int sc, int idx)
    {
        this->fs = fs, this->sc = sc, this->idx = idx;
    }
    friend bool operator<(node a, node b)
    {
        if ( a.fs != b.fs ) return a.fs < b.fs;
        return a.sc < b.sc;
    }
}L[MAX];

int rnk[22][MAX];

void pre()
{
    for ( int i = 0; i < n; i++ ) rnk[0][i] = s[i] - 'a';

    for ( int stp = 1; (1 << stp) < n; stp++ ) {
        for ( int i = 0; i < n; i++ ) {
            L[i].fs = rnk[stp - 1][i];
            L[i].sc = (i + (1 << (stp - 1))) < n  ? rnk[stp - 1][i + (1 << (stp - 1))] : -1;
            L[i].idx = i;
        }
        sort(L, L + n);
        for ( int i = 0; i < n; i++ ) {
            if ( i > 0 && L[i].fs == L[i - 1].fs && L[i].sc == L[i - 1].sc  ) rnk[stp][L[i].idx] = rnk[stp][L[i - 1].idx];
            else rnk[stp][L[i].idx] = i;
        }
    }

    return;
}

bool chk(int mid)
{
    return lexicographical_compare(s.begin() + L[mid].idx, s.end(), p.begin(), p.end());
}

int main()
{
    int t,q;

    cin >> t;

    while ( t-- ) {

        cin >> s;
        n = (int)s.size();

        pre();

        cin >> q;

        while ( q-- ) {

            cin >> p;
            sz = (int)p.size();

            int l = 0, r = n - 1, mid, idx, cnt = 0;

            while ( l <= r ) {
                mid = (l + r)/2;
                if ( !chk(mid) ) {
                    idx = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }

            for ( int i = 0; i < sz && i < n - L[idx].idx; i++ ) {
                if ( p[i] != s[i + L[idx].idx] ) break;
                cnt++;
            }

            char pp = ((cnt == sz) ? 'y' : 'n');

            cout << pp << endl;
        }

    }
    return 0;
}
