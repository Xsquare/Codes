#include <bits/stdc++.h>
#define MAX 5000005

using namespace std;

string s;
int z[MAX];

void compute() {
	z[0] = 0;
	int l = 0, r = 0, n = (int)s.size();
	for ( int i = 1; i < n; i++ ) {
		if ( i <= r ) z[i] = min(z[i - l], r - i + 1);
		while ( i + z[i] < n && s[z[i]] == s[i + z[i]] ) z[i]++;
		if ( i + z[i] - 1 > r ) l = i, r = i + z[i] - 1;
	}
}

int main()
{
	int q, x;
	
	cin >> s;
	compute();

	return 0;
}
