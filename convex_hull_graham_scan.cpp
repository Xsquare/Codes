#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define pii pair<int,int>
struct node
{
    int x;
    int y;
    double ang;
};
bool sort_by_ang( const node & lhs, const node & rhs )
{
   return lhs.ang < rhs.ang;
}
int main()
{
    int n;
    cin>>n;
    int A[n],B[n],l_y=1000000,l_x=1000000;
    for(int i=0;i<n;i++)
    {
        cin>>A[i]>>B[i];
        if(B[i]<l_y)
        {
            l_y=B[i];
            l_x=A[i];
        }
        else if(B[i]==l_y)
        {
            if(l_x>A[i])
                l_x=A[i];
        }
    }
/*
11
0 0
0 1
1 0
1 1
1 2
2 0
2 1
2 2
3 0
3 1
4 0
*/
    //cout<<l_x<<" "<<l_y<<"\n";
    //system("pause");
    vector<node> v(n-1);
    int p=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]!=l_x || B[i]!=l_y)
        {
            v[p].x = A[i];
            v[p].y = B[i];
            v[p].ang = atan2(B[i]-l_y,A[i]-l_x);
            //cout<<A[i]<<" "<<B[i]<<" "<<v[p].ang<<"*\n";
            p++;
        }
    }
    //system("pause");
    sort(v.begin(),v.end(),sort_by_ang);
    stack<pii> s;
    s.push(pii(l_x,l_y));
    //cout<<v[0].x<<" "<<v[0].y<<"\n";
    s.push(pii(v[0].x,v[0].y));
    //system("pause");
    for(int i=1;i<n-1;i++)
    {
        while(1)
        {
        if(s.size()<2)
        {
            s.push(pii(v[i].x,v[i].y));
            //cout<<v[i].x<<" "<<v[i].y<<" "<<s.size()<<"size<2\n";
            break;
        }
        pii x1,x2;
        x2.first=(s.top()).first;
        x2.second=(s.top()).second;
        s.pop();
        x1.first=(s.top()).first;
        x1.second=(s.top()).second;
        s.push(pii(x2.first,x2.second));
        int val=(x1.first-x2.first)*(v[i].y-x2.second)-(x1.second-x2.second)*(v[i].x-x2.first);
        if(s.size()>=2 && val>=0)
        {
            s.pop();
            //cout<<v[i].x<<" "<<v[i].y<<" "<<s.size()<<"val<=0\n";
        }
        else
        {
            s.push(pii(v[i].x,v[i].y));
            //cout<<v[i].x<<" "<<v[i].y<<" "<<s.size()<<"val>0\n";
            break;
        }
        }
    }
    while(!s.empty())
    {
        cout<<(s.top()).first<<" , "<<(s.top()).second<<"\n";
        s.pop();
    }
    system("pause");
    return 0;
}
        
        
        
    
        
    
