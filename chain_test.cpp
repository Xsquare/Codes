#include <bits/stdc++.h>

using namespace std;

vector <int> v[100005];
bool vis[100005];
bool in[100005];

bool f(int curr)
{
	in[curr] = true;
	vis[curr] = true;
	bool ans = false;
	for ( int i = 0; i < v[curr].size(); i++ ) {
		if ( in[v[curr][i]] ) {
			ans = true;
			return ans;
		}
		if ( !vis[v[curr][i]] ) ans = ans || f(v[curr][i]);
		if ( ans ) return ans;
	}
	in[curr] = false;
	return ans;
}

int main() {
	int n,m,x,y;
	cin >> n >> m;
	while ( m-- ) {
		cin >> x >> y;
		v[x].push_back(y);
	}
	bool ans = false;
	for ( int i = 1; i <= n; i++ ) {
		if ( !vis[i] ) {
			ans = ans | f(i);
			if ( ans ) break;
		}
	}
	if ( ans ) cout << "cycle" << endl;
	else cout << "not a cycle" << endl;
	return 0;
}
