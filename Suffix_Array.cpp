#include <bits/stdc++.h>
#define MAX 200005

using namespace std;

struct node {
	int fs;
	int sc;
	int idx;
}tmp[MAX];

int rnk[MAX][22];
int step;
int n;

bool cmp(node a, node b)
{
	if ( a.fs == b.fs ) return a.sc < b.sc;
	return a.fs < b.fs;
}

int lcp(int x, int y)
{
    int ans = 0;
    for ( int i = step; i >= 0; i-- ) {
        if ( max(x, y) + (1 << i) - 1 >= n ) continue;
        if ( rnk[x][i] == rnk[y][i] ) {
            x += (1 << i), y += (1 << i);
            ans += (1 << i);
        }
    }
    return ans;
}

int main()
{
	int q, x;
	string s;
	
	cin >> s;
	reverse(s.begin(), s.end());
	
	n = (int)s.size();
	
	for ( int i = 0; i < n; i++ ) {
		rnk[i][0] = s[i] - 'a';		
	}
	
	for ( step = 1; (1 << step) <= n; step++ ) {
		for ( int i = 0; i < n; i++ ) {
			tmp[i].fs = rnk[i][step - 1];
			if ( i + (1 << (step - 1)) < n ) {
				tmp[i].sc = rnk[i + (1 << (step - 1))][step - 1];
			}
			else	tmp[i].sc = -1;
			tmp[i].idx = i;
		}
		sort(tmp, tmp + n, cmp);
		for ( int i = 0; i < n; i++ ) {
			rnk[tmp[i].idx][step] = i;
			if ( i > 0 && tmp[i].fs == tmp[i - 1].fs && tmp[i].sc == tmp[i - 1].sc ) rnk[tmp[i].idx][step] = rnk[tmp[i - 1].idx][step];
		}
	}
	
	step--;
	
	cin >> q;
	while ( q-- ) {
	    cin >> x;
	    cout << lcp(0, n - x) << endl;
	}
	return 0;
}
