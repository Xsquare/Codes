#include <bits/stdc++.h>

using namespace std;

vector < pair<int, pair<int,int> > > v;
int ans[200005];
int A[30005];
int cnt;
int blocks;
int vis[1000005];

void add(int pos)
{
    return;
}

void rem(int pos)
{
    return;
}

bool func(pair <int, pair<int,int> > p1, pair <int, pair<int,int> > p2)
{
    if ( p1.second.first/blocks != p2.second.first/blocks ) return (p1.second.first)/blocks < (p2.second.first)/blocks;
    return p1.second.second < p2.second.second;
}

int main()
{
    int n,q,x,y,l=0,r=0,m;
    cnt = 0;

    scanf("%d", &n);
    blocks = (int)sqrt(n);
    for ( int i = 0; i < n; i++ ) scanf("%d", &A[i]);

    scanf("%d", &q);

    for ( int i = 0; i < q; i++ ) {
        scanf("%d%d", &x, &y);
        x--,y--;
        v.push_back(make_pair(i,make_pair(x,y)));
    }

    sort(v.begin(),v.end(),func);

    int L = 0 ,R = 0;
    add(0);
    for(int i = 0; i < m; ++i){
        int st = v[i].second.first, en = v[i].second.second;
        while(R > en){
            rem(R);
            --R;
        }
        while(R < en){
            ++R;
            add(R);
        }
        while(L > st){
            --L;
            add(L);
        }
        while(L < st){
            rem(L);
            ++L;
        }
        // store answer here
    }

    for ( int i = 0; i < q; i++ ) printf("%d\n", ans[i]);
    return 0;
}
