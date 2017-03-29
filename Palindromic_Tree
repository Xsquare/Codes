/**
    Palindromic tree data structure
**/
    
#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

string s;
int n;
int curr_node;
int tot_nodes;

struct node {
	
  /* Length of the longest suffix palindrome for the node */
	int suffix_len;
	
  /* Points to the node having the longest suffix palindrome */
	int suffix_edge;
	
  /* Insertion edge */
	int nxt[26];
  
  /* Index of the last character with respect to given string for this node */
	int end_idx;
  
}tree[MAX];

void insert(int idx)
{
	int ptr = curr_node;
	while ( 1 ) {
		int curr_len = tree[ptr].suffix_len;
		if ( idx - curr_len - 1 >= 0 && s[idx] == s[idx - curr_len - 1] ) break;
		ptr = tree[ptr].suffix_edge;
	}
	
	if ( tree[ptr].nxt[s[idx] - 'a'] != 0 ) {
		curr_node = tree[ptr].nxt[s[idx] - 'a'];
		return;
	}
	
	tree[ptr].nxt[s[idx] - 'a'] = ++tot_nodes;
	curr_node = tree[ptr].nxt[s[idx] - 'a'];
	tree[curr_node].suffix_len = tree[ptr].suffix_len + 2;
	tree[curr_node].end_idx = idx;

	if ( tree[curr_node].suffix_len == 1 ) {
		tree[curr_node].suffix_edge = 2;
		return;
	}
	
	ptr = tree[ptr].suffix_edge;
	
	while ( 1 ) {
		int curr_len = tree[ptr].suffix_len;
		if ( idx - curr_len - 1 >= 0 && s[idx] == s[idx - curr_len - 1] ) break;
		ptr = tree[ptr].suffix_edge;
	}
	
	tree[curr_node].suffix_edge = tree[ptr].nxt[s[idx] - 'a'];
}

int main()
{
	cin >> n;
	cin >> s;
	
	tree[1].suffix_len = -1, tree[1].suffix_edge = 1;
	tree[2].suffix_len = 0, tree[2].suffix_edge = 1;
	
	tot_nodes = 2;
	curr_node = 1;
	
	for ( int i = 0; i < n; i++ ) {
		insert(i);
	}
	
	return 0;
}
