struct node {
	int val;
	node *left, *right;
	node() { }
	node(int val, node *left, node *right)
	{
		this->val = val, this->left = left, this->right = right;
	}
};

node *segment[2000005];

//Adds value val at particular index
void update(node *prev, node *curr, int left, int right, int idx, int val)
{
	if ( left > right || left > idx || right < idx ) return;
	if ( left == right ) {
		curr->val = prev->val + val;
		return;
	}
	int mid = (left + right)/2;
	if ( idx <= mid ) {
		curr->right = prev->right;
		curr->left = new node(0, NULL, NULL);
		update(prev->left, curr->left, left, mid, idx, val);
	}
	else {
		curr->left = prev->left;
		curr->right = new node(0, NULL, NULL);
		update(prev->right, curr->right, mid + 1, right, idx, val);
	}
	curr->val = curr->left->val + curr->right->val;
}

//Queries the sum of values in range (i, j) at curr node of the persistent segment tree.
int query(node *curr, int left, int right, int i, int j)
{
	if ( left > right || left > j || right < i ) return 0;
	if ( left >= i && right <= j ) return curr->val;
	int mid = (left + right)/2;
	return query(curr->left, left, mid, i, j) + query(curr->right, mid + 1, right, i, j);
}

void build(node *curr, int left, int right)
{
	curr->right = curr->left = new node(0, NULL, NULL);
	if ( left == right ) return;
	int mid = (left + right)/2;
	build(curr->left, left, mid);
	build(curr->right, mid + 1, right);
}

int main()
{
  node *root = new node(0, NULL, NULL);
	build(root, 0, n - 1);
	
	segment[0] = root;
  
  //populate the segment array now.
  
  return 0;
}
