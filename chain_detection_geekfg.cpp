#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
 
bool isCyclicUtil(vector <int> adj[], int v, bool visited[], bool recStack[])
{
    if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;
 
        vector<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(adj, *i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
 
    }
    recStack[v] = false;
    return false;
}

bool func(vector <int> adj[], int n)
{
    bool visited[n+2];
    bool recStack[n+2];
    for(int i = 0; i <= n; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    for(int i = 1; i <= n; i++)
        if (isCyclicUtil(adj, i, visited, recStack))
            return true;
 
    return false;
}
 
int main()
{

    vector <int> v[10002];
	
	int n,m,i,x,y;
	
	cin >> n >> m;
	
	for ( i = 0; i < m; i++ ) {
		cin >> x >> y;
		v[x].push_back(y);
	}    	
    	
	if( func(v,n) )
        	printf("IMPOSSIBLE\n");
	else 
	     printf("sasda");
       system("pause");
	return 0;
}
