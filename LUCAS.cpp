#include <iostream>
using namespace std;
int choose[1009][1009];
int main() {
    for (int i=0; i<1009; i++) {
        choose[i][0]=choose[i][i]=1;
        for (int j=1; j<i; j++) choose[i][j] = (choose[i-1][j]+choose[i-1][j-1])%1009;
    }
    int T; scanf("%d",&T); while (T--) {
        long long N,K; scanf("%lld %lld",&N,&K);
        int ret = 1;
        while (N>0 || K>0) {
              int a = N%1009;
              int b = K%1009;
              N/=1009;
              K/=1009;
              if (a<b) ret = 0;
              else ret = (ret*choose[a][b])%1009;
        }
        printf("%d\n",ret);
    }
}
