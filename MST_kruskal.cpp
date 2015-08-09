#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#define edge pair <int,int>
#define MAX 5005

using namespace std;

vector< pair<double,edge> > GRAPH,MST;
int parent[MAX], N, E;
double total;

int findset(int x, int *parent)
{
    if(x != parent[x])
        parent[x] = findset(parent[x], parent);
    return parent[x];
}

void kruskal()
{
    int i, pu, pv;
    sort(GRAPH.begin(), GRAPH.end()); // increasing weight

    for(i=0; i<E; i++)
    {
        pu = findset(GRAPH[i].second.first, parent);
        pv = findset(GRAPH[i].second.second, parent);
        if(pu != pv)
        {
            MST.push_back(GRAPH[i]); // add to tree
            total += GRAPH[i].first; // add edge cost
            parent[pu] = parent[pv]; // link
        }
    }
}

void reset()
{
    // reset appropriate variables here
    MST.clear();
    GRAPH.clear();
    total = 0;
    
    //Vertices numbered from 0 to N-1
    for(int i=0; i<N; i++) parent[i] = i;
}

 
int main()
{
    int i, u, v;
    double w;
    int t;
    scanf("%d",&t);

    while(t--){
          scanf("%d %d", &N, &E);
          reset();
              
          for(i=0; i<E; i++)
          {
              scanf("%d %d %lf", &u, &v, &w);
              u--;
              v--;
              GRAPH.push_back(pair< double, edge >(w, edge(u, v)));
          }
          
          kruskal(); // runs kruskal and construct MST vector
          
          printf("%0.2lf\n",total); 
    }
    return 0;
}
