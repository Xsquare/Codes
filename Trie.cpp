struct trie {
    int pos[2];
    int cnt;
    trie() {
    	pos[0] = pos[1] = -1;
    	cnt = 0;
    }
}tree[15*1000005];

void add(int idx, int num, int where)
{
    tree[where].cnt++;
    if ( idx == -1 ) return;
    int bit_set = ((num&(1<<idx)) > 0);
    if ( tree[where].pos[bit_set] == -1 ) {
        tot++;
        tree[where].pos[bit_set] = tot;
    }
    add(idx-1, num, tree[where].pos[bit_set]);
}

void rem(int idx, int num, int where)
{
    tree[where].cnt--;
    if ( idx == -1 ) return;
    int bit_set = ((num&(1<<idx)) > 0);
    rem(idx-1, num, tree[where].pos[bit_set]);
    if ( tree[tree[where].pos[bit_set]].cnt <= 0 ) tree[where].pos[bit_set] = -1;
}

void add(int idx)
{
    add(29,A[idx],0);
}

void rem(int idx)
{
    rem(29,A[idx],0);
}
