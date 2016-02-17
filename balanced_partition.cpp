// Balanced partitioning
#include <bits/stdc++.h>
#define lli long long
#define pll pair <lli, lli>
using namespace std;
pll func(vector <lli> A)
{

	int n = (int)A.size(); // size of vector
    int Lsz = 1 << n/2;    // size of sumL
    int Rsz = 1 << (n - n/2);    //size of sumR

	lli sumL[Lsz+2],sumR[Rsz+2],totalSum = 0,temp,sum;

    for( int i = 0 ; i < Lsz ; i++){
            temp = 0;
            for( int j = 0 ; j < A.size()/2 ; j++){
                    if( (i & (1 << j)) > 0 ) temp +=  A[j];
            }
            sumL[i] = temp;
    }

    for(int i = 0 ; i < Rsz ; i++) {
    		temp = 0;
            for(int j = 0 ; j < n-n/2 ; j++){
                    if( (i&(1<<j)) > 0 ) temp += A[j + n/2];
            }
            sumR[i] = temp;
    }
    sort( sumL , sumL+Lsz );
    sort( sumR , sumR+Rsz );
    for(int i = 0 ; i < n ; i++) totalSum += A[i];
    lli cur = LLONG_MIN;
    int PL=0,PR=Rsz-1;
    while(PL < Lsz && PR >= 0){
            if(2LL*(sumL[PL]+sumR[PR]) <= totalSum ){
                    cur = max( cur , sumL[PL]+sumR[PR]);
                    PL++;
            }
            else PR--;
    }
	return make_pair(cur,totalSum-cur);
}
