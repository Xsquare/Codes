#include <bits/stdc++.h>

typedef long long LL;
using namespace std;

char s[20];
LL factorial[20];

void preProcess()
{
  factorial[0] = 1;
  for(long long i = 1; i <= 20; i++)
   factorial[i] = i * factorial[i - 1];
}

void findRank()
{
  long long n = strlen(s);
  long long frequency[25] = {0};
  LL denominator = 1;
  LL ans = 0;

  for(long long i = n - 1; i >= 0; i--)
  {
    frequency[s[i] - '0']++;
    denominator *= frequency[s[i] - '0'];
    for(long long c = 0; c < s[i] - '0'; c++)
     if(frequency[c])
      ans += factorial[n - i - 1] * frequency[c] / (denominator);
  }

  printf("%lld\n", ans + 1) ;
}

int main()
{
  int t;
  preProcess();
  scanf("%d", &t);
  while(t--)
  {
    scanf("%s", s);
    findRank();
  }
  return 0;
}
