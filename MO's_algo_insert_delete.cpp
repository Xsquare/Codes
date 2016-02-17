#include <bits/stdc++.h>
#define bsize 256

using namespace std;

// fast input
template<typename T>
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

int n,m,k,ar[1<<20],l[1<<20],r[1<<20];
vector<pair<int, int> > buck[1<<20];
int ql,qr;
int ans[1<<20];
int lent[1<<20];
int le[1<<20],ri[1<<20];
int qans;
vector<pair<pair<int, int> ,int> > ev;
int memans;

void add_item_b(int id)
{
    ri[ar[id]] = id;
    if ( le[ar[id]] > n ) le[ar[id]] = id;
    if ( ri[ar[id]]-le[ar[id]] > qans ) qans = ri[ar[id]]-le[ar[id]];
}

void add_item_f(int id)
{
    ev.push_back(make_pair(make_pair(ar[id],le[ar[id]]),0));
    ev.push_back(make_pair(make_pair(ar[id],ri[ar[id]]),1));
    le[ar[id]] = id;
    if ( ri[ar[id]] < 0 ) ri[ar[id]] = id;
    if ( ri[ar[id]]-le[ar[id]] > qans) qans = ri[ar[id]]-le[ar[id]];
}

void unroll()
{
   pair<pair<int, int>, int> tp;
   tp = ev.back();
   if ( tp.second == 0 ) le[tp.first.first] = tp.first.second;
   else ri[tp.first.first] = tp.first.second;
   ev.pop_back();
}

int main()
{
    fi(&n), fi(&m), fi(&k);
    for ( int i = 1; i <= n; i++ ) fi(&ar[i]);

    for (int i = 1;i <= k;i++) {
        fi(&l[i]), fi(&r[i]);
        if ( r[i]-l[i] >= bsize ) buck[l[i]/bsize].push_back(make_pair(r[i],i));
        else {
            for ( int j = l[i]; j <= r[i]; j++ ) lent[ar[j]] = 1e9;
            for ( int j = l[i]; j <= r[i]; j++ ) {
                ans[i] = max(ans[i],j-lent[ar[j]]);
                if ( lent[ar[j]] > n ) lent[ar[j]] = j;
            }
        }
    }

    for ( int i = 0; i <= n/bsize; i++) {
        for ( int j = 1; j <= m; j++ ) le[j] = 1e9,ri[j] = -1e9;
        sort(buck[i].begin(),buck[i].end());
        qr = ql = bsize*i+bsize;
        if ( ql > n )ql = n+1;
        ql++;
        qans = 0;
        for ( int j = 0; j < buck[i].size(); j++) {
             int id = buck[i][j].second;
             for ( int q = qr+1; q <= r[id]; q++ ) add_item_b(q);
             qr = r[id];
             memans =  qans;
             for ( int q = ql-1; q >= l[id]; q-- ) add_item_f(q);
             ans[id] = qans;
             while ( !ev.empty() ) unroll();
             qans = memans;
        }
    }
    for ( int i = 1; i <= k; i++ ) printf("%d\n", ans[i]);
    return 0;
}
