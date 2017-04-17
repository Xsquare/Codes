#include <bits/stdc++.h>
#define MAX 50004

using namespace std;

vector < pair<int, pair<int,int> > > v;
int ans[MAX];
int A[MAX];
int blocks;

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
    int n,q,x,y;

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
    for(int i = 0; i < q; ++i){
        int st = v[i].second.first, en = v[i].second.second;
        
        while ( L < st ) {
            rem(L);
            L++;
        }
        while ( R <= en ) {
            add(R);
            R++;
        }
        while ( L > st ) {
            add(L - 1);
            L--;
        }
        while ( R > en + 1) {
            rem(R - 1);
            R--;
        }
        // store answer here
    }

    for ( int i = 0; i < q; i++ ) printf("%d\n", ans[i]);
    return 0;
}
