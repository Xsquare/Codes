#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
void func(int **adj,int V[],int j)
{
     stack<int> s;
     s.push(j); // node from which to start
     while(!(s.empty()))
     {
                        int p=s.top();s.pop();
                        for(int i=0;i<sizeof(V);i++) //sizeof(V)
                        {
                                if(i==p) continue;
                                if(adj[p][i]==1 && V[i]==0)
                                {
                                                V[i]=1;
                                                s.push(i);
                                }
                        }
     }
}
int main()
{
    int n,m;
    cin>>n>>m;
    
    int **adj=(int**)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) adj[i]=(int*)malloc(m*sizeof(int));
    
    int V[n];
    memset(V,0,sizeof(V));
    
    for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                    cin>>adj[i][j];
                    
    int j;
    cin>>j; //j se kon-kon connected hai
    
    V[j]=1;
    func(adj,V,j); //V array mein 1 aa jaayega un index pe jo connected hain
    
    for(int i=0;i<n;i++) cout<<V[i]<<" ";
    
    system("pause");
    return 0;
}
    
