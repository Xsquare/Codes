#include<iostream>
#include<cmath>
using namespace std;
#define ll long long int
#define mx 1000001
ll A[mx];
void prime()
{
     A[0]=A[1]=1;
     for(int i=2;i<sqrt(mx);i++)
             if(!A[i])
                      for(int j=i*i;j<mx;j+=i)
                              A[j]=1;
}
    
    
    
