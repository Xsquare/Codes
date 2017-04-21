#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

vector <int> v[MAX];
int entry[MAX];
int order[MAX];
int child[MAX];
int timer = 0;

void dfs(int curr, int prev)
{
	entry[curr] = timer;
	order[timer] = curr;
	child[curr] = 1;
	
	timer++;
	
	for ( int i = 1; i < 20; i++ ) up[curr][i] = -1;
	
	for ( int i = 0; i < (int)v[curr].size(); i++ ) {
		if ( v[curr][i] == prev ) continue;
		dfs(v[curr][i], curr);
		child[curr] += child[v[curr][i]];
	}
}

void add(int x)
{
	//your logic
}

void _remove(int x)
{
	//your logic
}

void f(int curr, int prev, int keep)
{
	int big_child = -1, mx_size;
	
	//Find the heaviest child in the subtree of current node
	for ( int i = 0; i < (int)v[curr].size(); i++ ) {
		if ( v[curr][i] == prev ) continue;
		if ( big_child == -1 || child[v[curr][i]] > mx_size ) {
			mx_size = child[v[curr][i]];
			big_child = v[curr][i];
		}
	}
	
	//Clear the values of the light childs first
	for ( int i = 0; i < (int)v[curr].size(); i++ ) {
		if ( v[curr][i] == prev || v[curr][i] == big_child ) continue;
		f(v[curr][i], curr, 0);
	}
	
	//Do not clear the values of the heaviest child
	if ( big_child != -1 ) 
		f(big_child, curr, 1);
		
	//Since, you have the values for the heaviest child, you dont need to add them
	// You just need to add the values for the light childs.
	for ( int i = 0; i < (int)v[curr].size(); i++ ) {
		if ( v[curr][i] == prev || v[curr][i] == big_child ) continue;
		for ( int j = entry[v[curr][i]]; j < entry[v[curr][i]] + child[v[curr][i]]; j++ ) {
			add(order[j]);
		}
	}
	
	add(curr);
	
	//answer your queries here
	
	//Since, it's a light child, remove the values.
	if ( keep == 0 ) {
		for ( int j = entry[curr]; j < entry[curr] + child[curr]; j++ ) {
			_remove(order[j]);
		}
	}
}
