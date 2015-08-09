#include<iostream>
#include<cstring>
using namespace std;
#define md 1000000007
#define ll long long int
#define mx 2
ll A[mx][mx];
ll B[mx][mx];
void init()
{
     memset(A,0,sizeof(A));
     for(int i=0;i<mx;i++)
             A[i][i]=1;
     B[0][0]=1;B[0][1]=1;B[1][0]=1;B[1][1]=0;
}
void mul(ll A1[mx][mx],ll A2[mx][mx])
{
     ll C[mx][mx];
     memset(C,0,sizeof(C));
     for(int i=0;i<mx;i++)
             for(int j=0;j<mx;j++)
                     for(int k=0;k<mx;k++)
                             C[i][j]=(C[i][j]+A1[i][k]*A2[k][j])%md;
     for(int i=0;i<mx;i++)
             for(int j=0;j<mx;j++)
                     A[i][j]=C[i][j];
}
void func(ll n)
{
     if(n>1)
     {
            func(n/2);
            mul(A,A);
     }
     if(n&1)
            mul(A,B);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
              init();
              ll n;
              cin>>n;
              if(n==1) cout<<"0\n";
              else if(n==2) cout<<"1\n";
              else
              {
                  func(n-2);
                  cout<<A[0][0]<<"\n";
              }
    }
    return 0;
}
