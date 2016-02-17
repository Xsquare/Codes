#include <bits/stdc++.h>

using namespace std;

int iff[32];
int tot;

int tree[1000005][2];

void insert(int idx, int num)
{
    if ( idx == -1 ) return;
    if ( tree[num][iff[idx]] == -1 ) tree[num][iff[idx]] = tot++;
    insert(idx-1,tree[num][iff[idx]]);
}

int query(int idx, int num)
{
    if ( idx == -1 ) return 0;
    if ( tree[num][iff[idx]^1] != -1 ) return (1<<idx) + query(idx-1,tree[num][iff[idx]^1]);
    else return query(idx-1,tree[num][iff[idx]]);
}

int main()
{
    int n,ans=0,x;
    memset(tree, -1, sizeof(tree));
    tot = 1;
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        cin >> x;
        for ( int j = 0; j < 32; j++ ) {
            if ( (x&(1<<j)) ) iff[j] = 1;
            else iff[j] = 0;
        }
        insert(31,0);
        ans = max(ans, query(31,0));
    }
    cout << ans << endl;
    return 0;
}
//00000000000000000001
//00000000000000000010
